#include "symbolTable.h"
#include "ASTnode.h"
#include <iostream>
#include <fstream>
using namespace std;

extern string itos(int num);

extern _SymbolTable* mainSymbolTable;
extern _SymbolTable* currSymbolTable;
extern _SymbolRecord* findSymbolRecord(_SymbolTable* currSymbolTable, string id, int mode = 0);
extern bool isParamRef(_SymbolTable* currSymbolTable, string id);

//头文件
vector<string> vecHeadFile; 
//全局常量
vector<string> vecConstId;
vector<string> vecConstType;
vector<string> vecConstValue;
//全局变量
vector<string> vecVariantId;
vector<string> vecVariantType;
vector<vector<int>> vecArraySize;

struct subPrgmDeclare //子程序接口声明
{
	string returnType;//子程序返回值类型
	string id;//子程序名称标识符
	vector<string> vecParmId;//参数标识符
	vector<bool> vecParmIsRef;//参数是否为引用
	vector<string> vecParmType;//参数类型
	void clear()
	{
		vecParmId.clear();
		vecParmIsRef.clear();
		vecParmType.clear();
	}
};

vector<subPrgmDeclare> vecSubPrgmDeclare;//子程序声明

struct subPrgmDefine //子程序定义
{
	vector<string> vecConstId;
	vector<string> vecConstType;
	vector<string> vecConstValue;

	vector<string> vecVariantId; 
	vector<string> vecVariantType;
	vector<vector<int>> vecArraySize;

	vector<pair<string, int>> vecStatement;//语句
};

vector<subPrgmDefine> vecSubPrgmDefine;//子程序定义

string subMainFunctionDeclare;//主函数名
vector<pair<string, int>> vecStatement;//主程序语句

void codeGenerate(_Program* ASTRoot, string outName);
string transformType(string pascalType);
string transformOpertion(string operation, int mode = 0);

void getConstList(vector<_Constant*>&, vector<string>&, vector<string>&, vector<string>&, _SymbolTable*);//获取常数列表
void getVariant(vector<_Variant*>, vector<string>&, vector<string>&, vector<vector<int>>&, _SymbolTable*);//获取变量列表
void getSubPrgmDeclare();//获取子程序声明列表
void getFunctionCall(_FunctionCall*, string&, int mode = 0);//获取函数调用
int getExpression(_Expression*, string&, int mode = 0, bool isReferedActualPara = false);//获取表达式
void getVariantRef(_VariantReference*, string&, int mode = 0, bool isReferedActualPara = false);//获取变量引用
void getStatement(_Statement*, vector<pair<string, int>>&, int retract, int flag = 0);//获取语句列表
void getSubPrgmDefine(_FunctionDefinition*);//获取某个子程序定义
void getAllSubPrgmDefine(_SubProgram*);//获取全部子程序定义
void getSubMainFunction(_Program* ASTRoot);//获取主程序定义
string getOutputFormat(string type);//根据类型获取输入输出格式控制符
bool getLibSubPrgm(_ProcedureCall*, vector<pair<string, int>>&, int retract); //获取库程序

void genHeadFile();//生成头文件
void genConst(vector<string>& constIdList, vector<string>&, vector<string>&, int retract = 0);//生成常数
void genVariant(vector<string>&, vector<string>&, vector<vector<int>>&, int retract = 0);//生成变量
void genSubPrgmDeclare(const subPrgmDeclare&, int flag = 0);//生成某个子程序声明
void genSubPrgmDeclare();//生成全部子程序声明
void genStatement(pair<string, int>& tmp);//生成某条语句
void genStatementList(vector<pair<string, int>>& vec);//生成全部语句
void genSubPrgmDefine();//生成全部子程序定义
void genMain(_Program* ASTRoot);//生成主函数

ofstream fout;

void codeGenerate(_Program* ASTRoot, string outFile) {
	fout.open(outFile.c_str());
	
	currSymbolTable = mainSymbolTable;//定位到主符号表
	getSubPrgmDeclare();//子程序声明
	getConstList(ASTRoot->subProgram->constList, vecConstId, vecConstType, vecConstValue, currSymbolTable);//全局常量/主程序常量
	getVariant(ASTRoot->subProgram->variantList, vecVariantId, vecVariantType, vecArraySize, currSymbolTable);//全局变量/主程序变量
	getAllSubPrgmDefine(ASTRoot->subProgram);//子程序定义列表
	currSymbolTable = mainSymbolTable;//定位到主符号表
	getSubMainFunction(ASTRoot);//原PASCAL主程序对应C的程序头和语句体

	genHeadFile();
	genConst(vecConstId, vecConstType, vecConstValue);
	genVariant(vecVariantId, vecVariantType, vecArraySize);
	genSubPrgmDeclare();
	genMain(ASTRoot);
	genSubPrgmDefine();

	fout.close();
}

string transformType(string pascalType) {
	if (pascalType == "integer")
		return "int";
	if (pascalType == "real")
		return "float";
	if (pascalType == "boolean")
		return "bool";
	if (pascalType == "char")
		return "char";

	return "";
}

string transformOpertion(string operation, int mode) {
	if (mode != 0)
		return operation;
	if (operation == "not")
		return "!";
	if (operation == "=")
		return "==";
	if (operation == "<>")
		return "!=";
	if (operation == "or")
		return "||";
	if (operation == "div")
		return "/";
	if (operation == "mod")
		return "%";
	if (operation == "and")
		return "&&";
	return operation;
}

void getConstList(vector<_Constant*>& vecAllConst, vector<string>& constIdList, vector<string>& constTypeList, vector<string>& constValueList, _SymbolTable* symbolTable) {
	//初始化
	constIdList.clear();
	constTypeList.clear();
	constValueList.clear();

	for (auto* iter : vecAllConst)
	{
		constIdList.push_back(iter->constId.first);
		_SymbolRecord* record = findSymbolRecord(symbolTable, iter->constId.first, 1);
		string constVal;
		if (record->type != "char" && record->isMinusShow)
			constVal += "-";
		constVal += record->value;
		constTypeList.push_back(transformType(record->type));//从符号表获取常量类型
		constValueList.push_back(constVal);//从符号表获取常量值，要求是string形式
	}
}

void getVariant(vector<_Variant*> variantList, vector<string>& variantIdList, vector<string>& variantTypeList, vector<vector<int>>& arraySizeList, _SymbolTable* symbolTable) {
	//初始化
	variantIdList.clear();
	variantTypeList.clear();
	arraySizeList.clear();

	for (auto* iter : variantList)
	{
		variantIdList.push_back(iter->variantId.first);
		_SymbolRecord* record = findSymbolRecord(symbolTable, iter->variantId.first, 1);
		variantTypeList.push_back(transformType(record->type));//从符号表获取类型
		vector<pair<int, int>>& tmpRangeList = record->arrayRangeList;
		vector<int> tmpRange;
		for (auto range : tmpRangeList)
			tmpRange.push_back(range.second - range.first + 1);
		arraySizeList.push_back(tmpRange);
	}
}

void getSubPrgmDeclare() {
	subPrgmDeclare dec;
	for (auto* iter : mainSymbolTable->recordList)
	{
		_SymbolRecord* record = iter;
		if ((record->flag == "procedure" || record->flag == "function") && record->subSymbolTable) {
			dec.clear();
			dec.returnType = transformType(record->type);
			dec.id = record->id;
			_SymbolTable* subTable = record->subSymbolTable;
			for (int i = 1; i <= record->amount; i++) {
				dec.vecParmId.push_back(subTable->recordList[i]->id);
				if (subTable->recordList[i]->flag == "var parameter")
					dec.vecParmIsRef.push_back(true);
				else
					dec.vecParmIsRef.push_back(false);
				dec.vecParmType.push_back(transformType(subTable->recordList[i]->type));
			}
			vecSubPrgmDeclare.push_back(dec);
		}
	}
}

//mode表示是否需要将PASCAL运算符转化为C运算符
void getFunctionCall(_FunctionCall* functionCallNode, string& functionCall, int mode)
{
	functionCall = functionCallNode->functionId.first + "(";
	_SymbolRecord* record = findSymbolRecord(mainSymbolTable, functionCallNode->functionId.first);
	
	for (int i = 0; i < functionCallNode->actualParaList.size(); i++)
	{
		if (i > 0) functionCall += ", ";
		string expression; //需要检查对应的形参是否是引用参数
		getExpression(functionCallNode->actualParaList[i], expression, mode, record->isIdxParamRef(i + 1));
		functionCall += expression;
	}

	functionCall += ")";
}

//mode表示是否需要将PASCAL运算符转化为C运算符
int getExpression(_Expression* expressionNode, string& expression, int mode, bool isReferedActualPara) {
	//返回值用于表示是否需要加括号
	int flag;
	if (expressionNode->type == "var") //如果是变量标识符
	{
		string variantRef;//这里应该一定是右值，所以无需特判
		getVariantRef(expressionNode->variantReference, variantRef, mode, isReferedActualPara);
		expression += variantRef;
		return 0;
	}
	else if (expressionNode->type == "integer") //如果是整数
	{
		expression += expressionNode->strOfNum;
		return 0;
	}
	else if (expressionNode->type == "real") //如果是浮点数
	{
		expression += expressionNode->strOfNum;
		return 0;
	}
	else if (expressionNode->type == "char") //如果是字符常量
	{
		expression += string("'") + expressionNode->charVal + string("'");
		return 0;
	}
	else if (expressionNode->type == "function") //如果是函数调用
	{
		string functionCall;
		getFunctionCall(expressionNode->functionCall, functionCall, mode);
		expression += functionCall;
		return 0;
	}
	else if (expressionNode->type == "compound") //如果是复合表达式
	{
		if (expressionNode->operationType == "single") {//如果是单目运算符
			string tmp;
			flag = getExpression(expressionNode->operand1, tmp, mode);
			if (expressionNode->operation == "bracket") {//如果是括号
				expression += "(" + tmp + ")";
				return 0;
			}
			if (expressionNode->operation == "minus")//如果是取相反数
				expression += " - ";
			else if (expressionNode->operation == "not")//如果是取非
				expression += " " + transformOpertion(expressionNode->operation, mode) + " ";
			if (mode == 0 && flag > 0)
				expression += "(" + tmp + ")";
			else
				expression += tmp;
			return 4;
		}
		else if (expressionNode->operationType == "mulop") {//如果是"mulop"
			string tmp;
			flag = getExpression(expressionNode->operand1, tmp, mode);
			if (flag != 0 && flag < 3)
				expression += "(" + tmp + ") " + transformOpertion(expressionNode->operation, mode) + " ";
			else
				expression += tmp + " " + transformOpertion(expressionNode->operation, mode) + " ";
			tmp = "";
			flag = getExpression(expressionNode->operand2, tmp, mode);
			if (mode == 0 && flag != 0 && flag < 3)
				expression += "(" + tmp + ")";
			else
				expression += tmp;
			return 3;
		}
		else if (expressionNode->operationType == "addop") {//如果是"addop"
			string tmp;
			flag = getExpression(expressionNode->operand1, tmp, mode);
			if (flag == 1)
				expression += "(" + tmp + ") " + transformOpertion(expressionNode->operation, mode) + " ";
			else
				expression += tmp + " " + transformOpertion(expressionNode->operation, mode) + " ";
			tmp = "";
			flag = getExpression(expressionNode->operand2, tmp, mode);
			if (mode == 0 && flag == 1)
				expression += "(" + tmp + ")";
			else
				expression += tmp;
			return 2;
		}
		else if (expressionNode->operationType == "relop") {//如果是"relop"
			string tmp;
			getExpression(expressionNode->operand1, tmp, mode);
			expression += tmp + " " + transformOpertion(expressionNode->operation, mode) + " ";
			tmp = "";
			getExpression(expressionNode->operand2, tmp, mode);
			expression += tmp;
			return 1;
		}
	}

	return -1;
}

//mode表示是否需要将PASCAL运算符转化为C运算符
//有五种kind,"array","var","constant","function call","function return reference"
//左值特判
void getVariantRef(_VariantReference* variantRefNode, string& variantRef, int mode, bool isReferedActualPara)
{
	variantRef = variantRefNode->variantId.first;
	//如果是函数，一定是右值，如果是左值，代码逻辑保证了不会调用该函数
	//通过了语义分析，保证了该函数形参个数一定为0
	if (mode == 0 && (variantRefNode->kind == "var" || variantRefNode->kind == "array")) {
		bool isRefered = isParamRef(currSymbolTable, variantRefNode->variantId.first);
		if (isRefered) {
			if (!isReferedActualPara)
				variantRef = "*" + variantRef;
		}
		else {
			if (isReferedActualPara)
				variantRef = "&" + variantRef;
		}
	}
	if (mode == 0 && variantRefNode->kind == "function")
		variantRef += "()";
	if (variantRefNode->kind != "array")
		return;

	//这里得查符号表，找出数组定义时每一维的下界
	_SymbolRecord* record = findSymbolRecord(currSymbolTable, variantRefNode->variantId.first);
	if (mode == 0) { //如果生成C代码
		for (int i = 0; i < variantRefNode->expressionList.size(); i++) {
			string expression;
			getExpression(variantRefNode->expressionList[i], expression, mode);
			int lowBound = record->arrayRangeList[i].first;
			string delta;
			if (lowBound > 0)
				delta = " - " + itos(lowBound);
			else if (lowBound < 0)
				delta = " + " + itos(abs(lowBound));
			else
				delta = "";
			variantRef += "[" + expression + delta + "]";
		}
	}
	else {//如果按照原样输出
		variantRef += "[";
		for (int i = 0; i < variantRefNode->expressionList.size(); i++) {
			string expression;
			getExpression(variantRefNode->expressionList[i], expression, mode);
			if (i != 0)
				variantRef += ", ";
			variantRef += expression;
		}
		variantRef += "]";
	}
}

void getStatement(_Statement* statementNode, vector<pair<string, int>>& vecStatement, int retract, int flag)
{
	if (statementNode->type == "compound")
	{
		_Compound* compoundNode = reinterpret_cast<_Compound*>(statementNode);
		if (flag == 0)
			vecStatement.emplace_back(make_pair("{", retract - 1));
		for (auto iter : compoundNode->statementList)
			getStatement(iter, vecStatement, retract);
		if (flag == 0)
			vecStatement.emplace_back(make_pair("}", retract - 1));
	}
	else if (statementNode->type == "repeat")
	{
		_RepeatStatement* repeatStatementNode = reinterpret_cast<_RepeatStatement*>(statementNode);
		string condition;
		vecStatement.emplace_back(make_pair("do", retract));
		getStatement(repeatStatementNode->_do, vecStatement, retract + 1);
		getExpression(repeatStatementNode->condition, condition);
		condition = "while(!(" + condition + "));";
		vecStatement.emplace_back(make_pair(condition, retract));
	}
	else if (statementNode->type == "while")
	{
		string condition;
		_WhileStatement* whileStatementNode = reinterpret_cast<_WhileStatement*>(statementNode);
		getExpression(whileStatementNode->condition, condition);
		condition = "while(" + condition + ")";
		vecStatement.emplace_back(make_pair(condition, retract));
		getStatement(whileStatementNode->_do, vecStatement, retract + 1);
	}
	else if (statementNode->type == "for")
	{
		string start, end;
		_ForStatement* forStatementNode = reinterpret_cast<_ForStatement*>(statementNode);
		getExpression(forStatementNode->start, start);
		getExpression(forStatementNode->end, end);
		vecStatement.emplace_back(make_pair("for(" + forStatementNode->id.first + " = " + start + "; " + forStatementNode->id.first + " <= " + end + "; " + forStatementNode->id.first + "++)", retract));
		getStatement(forStatementNode->_do, vecStatement, retract + 1);
	}
	else if (statementNode->type == "if")
	{
		string condition;
		_IfStatement* ifStatementNode = reinterpret_cast<_IfStatement*>(statementNode);
		getExpression(ifStatementNode->condition, condition);
		vecStatement.emplace_back(make_pair("if(" + condition + ")", retract));
		getStatement(ifStatementNode->then, vecStatement, retract + 1);
		if (ifStatementNode->els != NULL) {
			vecStatement.emplace_back(make_pair("else", retract));
			getStatement(ifStatementNode->els, vecStatement, retract + 1);
		}
	}
	else if (statementNode->type == "assign")
	{//左值特判
		string variantRef;
		_AssignStatement* assignStatementNode = reinterpret_cast<_AssignStatement*>(statementNode);
		string expression;
		getExpression(assignStatementNode->expression, expression);
		if (assignStatementNode->variantReference->kind == "function return reference") {//如果是返回值语句
			variantRef = "return (" + expression + ");";
			vecStatement.emplace_back(make_pair(variantRef, retract));
		}
		else {
			getVariantRef(assignStatementNode->variantReference, variantRef);
			vecStatement.emplace_back(make_pair(variantRef + " = " + expression + ";", retract));
		}
	}
	else if (statementNode->type == "procedure")
	{
		_ProcedureCall* procedureCallNode = reinterpret_cast<_ProcedureCall*>(statementNode);
		if (getLibSubPrgm(procedureCallNode, vecStatement, retract))
			return;
		_SymbolRecord* record = findSymbolRecord(mainSymbolTable, procedureCallNode->procedureId.first);
		string procedureCall = procedureCallNode->procedureId.first + "(";
		for (int i = 0; i < procedureCallNode->actualParaList.size(); i++) {
			string expression;
			getExpression(procedureCallNode->actualParaList[i], expression, 0, record->isIdxParamRef(i + 1));
			if (i != 0)
				procedureCall += ", ";
			procedureCall += expression;
		}
		procedureCall += ");";
		vecStatement.emplace_back(make_pair(procedureCall, retract));
	}
	else cout << "unknown statement type";
}

void getSubPrgmDefine(_FunctionDefinition* functionDefinitionNode)
{
	_SymbolRecord* record = findSymbolRecord(mainSymbolTable, functionDefinitionNode->functionID.first);
	struct subPrgmDefine tmp;
	getConstList(functionDefinitionNode->constList, tmp.vecConstId, tmp.vecConstType, tmp.vecConstValue, record->subSymbolTable);
	getVariant(functionDefinitionNode->variantList, tmp.vecVariantId, tmp.vecVariantType, tmp.vecArraySize, record->subSymbolTable);
	getStatement(functionDefinitionNode->compound, tmp.vecStatement, 1, 1);
	vecSubPrgmDefine.push_back(tmp);
}

void getAllSubPrgmDefine(_SubProgram* subProgramNode)
{
	vecSubPrgmDefine.clear();
	for (auto* iter : subProgramNode->subprogramDefinitionList)
	{
		auto* record = findSymbolRecord(mainSymbolTable, iter->functionID.first);
		currSymbolTable = record->subSymbolTable;
		getSubPrgmDefine(iter);
	}
}

void getSubMainFunction(_Program* ASTRoot)
{
	subMainFunctionDeclare = "void " + ASTRoot->programId.first + "()";
	getStatement(ASTRoot->subProgram->compound, vecStatement, 1, 1);
}

string getOutputFormat(string type)
{
	if (type == "integer")
		return "%d";
	if (type == "real")
		return "%f";
	if (type == "char")
		return "%c";
	if (type == "boolean")
		return "bool";
	return "";
}

bool getLibSubPrgm(_ProcedureCall* procedureCall, vector<pair<string, int>>& vecStatement, int retract)
{
	string proCall;
	string& id = procedureCall->procedureId.first;
	if (id == "exit") {
		proCall += "return";
		if (!procedureCall->actualParaList.empty()) {
			string expression;
			getExpression(procedureCall->actualParaList[0], expression);
			proCall += " (" + expression + ")";
		}
		proCall += ";";
		vecStatement.emplace_back(make_pair(proCall, retract));
	}
	else if (id == "write" || id == "writeln") {
		if (id == "writeln" && procedureCall->actualParaList.empty()) {
			vecStatement.emplace_back(make_pair("printf(\"\\n\");", retract));
			return true;
		}
		proCall += "printf(\"";
		string exp;//exp按顺序保存了表达式
		for (int i = 0; i < procedureCall->actualParaList.size(); i++) {
			string expression, typeFormat;
			getExpression(procedureCall->actualParaList[i], expression);
			typeFormat = getOutputFormat(procedureCall->actualParaList[i]->expressionType);
			if (typeFormat == "bool") {
				if (!exp.empty()) {
					proCall += "\"" + exp + ");";
					vecStatement.emplace_back(make_pair(proCall, retract));
					proCall = "printf(\"";
					exp = "";
				}
				vecStatement.emplace_back(make_pair("{", retract));
				vecStatement.emplace_back(make_pair("if(" + expression + ")", retract + 1));
				vecStatement.emplace_back(make_pair("printf(\"true\");", retract + 2));
				vecStatement.emplace_back(make_pair("else", retract + 1));
				vecStatement.emplace_back(make_pair("printf(\"false\");", retract + 2));
				vecStatement.emplace_back(make_pair("}", retract));
				if (i == procedureCall->actualParaList.size() - 1 && id == "writeln")
					vecStatement.emplace_back(make_pair("printf(\"\\n\");", retract));
			}
			else {
				proCall += typeFormat;
				exp += ", " + expression;
			}
		}
		if (!exp.empty()) {
			if (id == "writeln")
				proCall += "\\n";
			proCall += "\"" + exp + ");";
			vecStatement.emplace_back(make_pair(proCall, retract));
		}
	}
	else if (id == "read") {
		proCall += "scanf(\"";
		string exp;
		for (auto* iter : procedureCall->actualParaList)
		{
			string expression, typeFormat;
			getExpression(iter, expression, 0, true);
			typeFormat = getOutputFormat(iter->expressionType);
			if (typeFormat == "bool") typeFormat = "%d";
			proCall += typeFormat;
			exp += ", " + expression;
		}

		proCall += "\"" + exp + ");";
		vecStatement.emplace_back(make_pair(proCall, retract));
	}
	return true;
}

void genHeadFile()
{
	vecHeadFile.emplace_back("stdio.h");
	vecHeadFile.emplace_back("stdbool.h");

	fout << "//Head files" << endl;
	for (auto iter : vecHeadFile) fout << "#include<" << iter << ">" << endl;
	fout << endl;
}

void genConst(vector<string>& constIdList, vector<string>& constTypeList, vector<string>& constValueList, int retract)
{
	const int n = int(constIdList.size());
	if (!n) return;
	if (!retract) fout << "//Overall constant definiton" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < retract; j++)
			fout << "\t";
		fout << "const " << constTypeList[i] << " " << constIdList[i] << " = " << constValueList[i] << ";" << endl;
	}

	fout << endl;
}

void genVariant(vector<string>& variantIdList, vector<string>& variantTypeList, vector<vector<int>>& arraySizeList, int retract) {
	int n = int(variantIdList.size());
	if (!n) return;
	if (!retract) fout << "//Overall variable definition" << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < retract; j++)
			fout << "\t";
		fout << variantTypeList[i] << " " << variantIdList[i];
		int m = int(arraySizeList[i].size());
		for (int j = 0; j < m; j++)
			fout << "[" << arraySizeList[i][j] << "]";
		fout << ";" << endl;
	}

	fout << endl;
}

void genSubPrgmDeclare(const subPrgmDeclare& tmp, int flag) //flag==0时表示接口声明,flag==1时表示定义时的子程序头
{
	string str = tmp.returnType.empty() ? "void" : tmp.returnType;
	fout << str << " " << tmp.id << "(";
	int m = int(tmp.vecParmId.size());
	for (int j = 0; j < m; j++) {
		if (j != 0)
			fout << ", ";
		fout << tmp.vecParmType[j] << " ";
		if (tmp.vecParmIsRef[j])
			fout << "*";
		fout << tmp.vecParmId[j];
	}
	fout << ")";
	if (flag == 0)
		fout << ";";
	fout << endl;
}

void genSubPrgmDeclare()
{
	if (vecSubPrgmDeclare.empty()) return;
	fout << "//Subprogram Declare" << endl;

	fout << subMainFunctionDeclare << ";" << endl; //main
	for (const auto iter : vecSubPrgmDeclare)
		genSubPrgmDeclare(iter, 0);

	fout << endl;
}

void genStatement(pair<string, int>& tmp)
{
	int n = tmp.second;
	for (int i = 0; i < n; i++)
		fout << "\t";
	fout << tmp.first << endl;
}

void genAllStatement(vector<pair<string, int>>& vec)
{
	int n = int(vec.size());
	for (int i = 0; i < n; i++)
		genStatement(vec[i]);
	vec.clear();//清空
}

void genSubPrgmDefine()
{
	fout << "//Subprogram definition" << endl;
	
	//主程序
	fout << subMainFunctionDeclare << endl;
	fout << "{" << endl;
	genAllStatement(vecStatement);
	fout << "}" << endl << endl;

	//其余子过程、子函数
	vector<subPrgmDefine>& def = vecSubPrgmDefine;
	for (int i = 0; i < def.size(); i++) {
		genSubPrgmDeclare(vecSubPrgmDeclare[i], 1);
		fout << "{" << endl;
		genConst(def[i].vecConstId, def[i].vecConstType, def[i].vecConstValue, 1);
		genVariant(def[i].vecVariantId, def[i].vecVariantType, def[i].vecArraySize, 1);
		genAllStatement(def[i].vecStatement);
		fout << "}" << endl << endl;
	}

	fout << endl;
}

void genMain(_Program* ASTRoot)
{
	fout << "//Main function" << endl;
	fout << "int main()\n{\n\t";
	fout << ASTRoot->programId.first + "()";
	fout << "; \n\treturn 0; \n}\n";
	fout << endl;
}