/*
主函数
*/
#include "PTnode.h"
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <Windows.h>

class _Program;

extern Type* ParseTreeHead;
extern FILE* yyin;
extern _Program* getProgram(Type *now);
extern int yydebug;
extern void SemanticAnalyse(_Program *ASTRoot);
extern vector<string> lexicalErrorInformation;
extern vector<string> syntaxErrorInformation;
extern vector<string> semanticErrorInformation;
extern vector<string> semanticWarningInformation;
extern void codeGenerate(_Program *ASTRoot, string outName);

extern "C"{
    int yyparse();
}

int errorCount = 0;
int errorBound = int(1e9 + 7); //默认错误上限，INF

void preProcess(string inName);
string char2str(char* chs);
bool chs2int(char* chs, int &num);
void dfsPT(Type* now); //遍历普通语法分析树
void outputErrors();

int main(int argc, char **argv){
	const string inFile = "code.pas"; //默认输入文件名
	const string outFile = "code.c"; //默认输出文件名

	preProcess(inFile); //预处理

	FILE* fp;
	errno_t err = fopen_s(&fp, inFile.c_str(), "r");
	if (err) return -1;
	yyin = fp;
	yyparse(); //调用语法分析程序
	fclose(fp);

	cout << "Lexical Analyzed" << endl;
	cout << "Syntax Analyzed" << endl;
	
	//dfsPT(ParseTreeHead);
	if (!lexicalErrorInformation.empty() || !syntaxErrorInformation.empty()) //如果有词法、语法错误
	{
		outputErrors();
		return 0;
	}

	//语义分析
	_Program* ASTRoot = getProgram(ParseTreeHead);
	SemanticAnalyse(ASTRoot);//语义分析

	if (!semanticErrorInformation.empty()) //如果有语义错误
	{
		outputErrors();
		return 0;
	}
	cout << "Semantic Analyzed" << endl;

	//代码生成
	codeGenerate(ASTRoot, outFile);
	cout << "Code Generated" << endl;

	return 0;
}

string char2str(char* chs) {
	string res;
	for (; *chs != 0; chs++)
		res += *chs;
	return res;
}

bool chs2int(char* chs, int &num) {
	int tmp = num;
	num = 0;
	for (; *chs != '\0'; chs++) {
		if (*chs >= '0'&&*chs <= '9') {
			num *= 10;
			num += *chs - '0';
		}
		else {
			num = tmp;
			return false;
		}
	}
	return true;
}

//普通语法树的debug信息（遍历输出）
void dfsPT(Type* now) {
	if (now->children.empty()) {
		if (now->str.empty())
			cout << now->token << "\t->\tempty" << endl;
		return;
	}
	cout << now->token << "\t->";

	for(auto* child:now->children)
	{
		if (child->children.empty() && !child->str.empty())
			cout << "\t\"" << child->str << "\"";
		else
			cout << "\t" << child->token;
	}
	cout << endl;

	for (auto* child : now->children)
		dfsPT(child);
}

void preProcess(string inFile){
	ifstream fin(inFile);
	ofstream fout("codePred.pas");

	string str;
	while (getline(fin,str)){
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		fout << endl << str;
	}
	
	fin.close();
	fout.close();
}

void outputErrors() {
	if (!lexicalErrorInformation.empty())
		for (auto info : lexicalErrorInformation)
			cout << info << endl;
	
	if (!syntaxErrorInformation.empty())
		for (auto info : syntaxErrorInformation)
			cout << info << endl;

	if(!semanticWarningInformation.empty())
		for (auto info : semanticWarningInformation)
			cout << info << endl;

	if (!semanticErrorInformation.empty())
		for (auto info : semanticErrorInformation)
			cout << info << endl;
}