/*
主函数
*/
#include "PTnode.h"
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <windows.h>

class _Program;//暂时只需要前向声明（后面也尽量保持这种状态）

extern Type* ParseTreeHead;
extern FILE* yyin;
extern _Program* getProgram(Type *now);
extern int yydebug;
extern bool haveSemanticError;
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
void dfs(Type* now);
void outputErrors();

int main(int argc, char **argv){
	string inName = "code.pas"; //默认输入文件名
	string outName = "code.c"; //默认输出文件名
	
	//yydebug=1;//语法分析DEBUG信息开关

	FILE *fp = NULL;
	fp = fopen(inName.c_str(), "r");
	if (fp == NULL) {
		cout << "Cannot open PASCAL-S file " << inName.c_str() << " , please check it." << endl;
		exit(0);
	}
	fclose(fp);

	cout << "Now start pre process..." << endl;
	preProcess(inName); //预处理

	//通过将打开文件指针赋值为yyin，给词法分析程序提供输入

	const char* sFile = "code.pas";

	fp = fopen(sFile,"r");
	if(fp==NULL){
		printf("Cannot open %s\n",sFile);
		return -1;
	}
	yyin=fp;
	cout << "Now start lex and syntax analyse..." << endl;
	haveSemanticError = false;
	yyparse();//调用语法分析程序
	fclose(fp);

	//dfs(ParseTreeHead); //遍历普通语法分析树

	bool canContinueToSemanticAnalyse = true;

	if (lexicalErrorInformation.size()) //如果有词法错误
		canContinueToSemanticAnalyse = false;
	else
		cout << "Lex analyse succeed!!!" << endl << endl; //没有词法错误

	if (haveSemanticError) //如果有语法错误
		canContinueToSemanticAnalyse = false;
	else if (canContinueToSemanticAnalyse)
		cout << "Syntax analyse succeed!!!" << endl << endl;

	if (!canContinueToSemanticAnalyse) { //如果有词法或语法错误
		outputErrors();
		system("pause");
		return 0;
	}

	//开始语义分析
	cout << "Now start semantic analysing..." << endl;
	_Program* ASTRoot=getProgram(ParseTreeHead);
	SemanticAnalyse(ASTRoot);//语义分析

	outputErrors();

	if (semanticErrorInformation.size()) { //如果有语义错误
		system("pause");
		return 0;
	}
	
	cout << "Semantic analyse succeed!!!" << endl << endl;

	//代码生成
	cout << "Now start generating the C Program code..." << endl;
	codeGenerate(ASTRoot, outName);
	cout << "Code Generate succeed!!!" << endl;
	cout << "Please check C code in " << outName << endl << endl;

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
void dfs(Type* now) {
	if (now->children.size() == 0) {
		if (now->str == "")
			cout << now->token << "\t->\t" << "empty" << endl;
		return;
	}
	cout << now->token << "\t->";
	for (int i = 0; i < now->children.size(); i++) {
		if (now->children[i]->children.size() == 0 && now->children[i]->str != "")
			cout << "\t\"" << now->children[i]->str << "\"";
		else
			cout << "\t" << now->children[i]->token;
	}
	cout << endl;
	for (int i = 0; i<now->children.size(); i++)
		dfs(now->children[i]);
}

void preProcess(string inName){
	ifstream fin(inName);
	ofstream fout("codePred.pas");
	string str;
	while (getline(fin,str)){
		for(int i=0;i<str.size();i++){
			if(str[i]>='A'&&str[i]<='Z')
				str[i]+='a'-'A';
		}
		fout << endl << str;
	}
	fin.close();
	fout.close();
}

void outputErrors() {
	if (lexicalErrorInformation.size()) { //如果有词法错误
		cout << "************************Here are the lexical errors***********************" << endl;
		for (int i = 0; i < lexicalErrorInformation.size(); i++)
			cout << lexicalErrorInformation[i] << endl;
		cout << "********************Please correct your lexical errors********************" << endl << endl;
	}
	if (syntaxErrorInformation.size()) { //如果有语法错误
		cout << "************************Here are the syntax errors***********************" << endl;
		for (int i = 0; i < syntaxErrorInformation.size(); i++)
			cout << syntaxErrorInformation[i] << endl;
		cout << "********************Please correct your syntax errors********************" << endl << endl;
	}
	if (semanticWarningInformation.size()) { //如果有语义警告
		cout << "*****************************Here are the semantic warnings****************************" << endl;
		for (int i = 0; i < semanticWarningInformation.size(); i++)
			cout << semanticWarningInformation[i] << endl;
		cout << "********************Please pay attention to these semantic warnings********************" << endl << endl;
	}
	if (semanticErrorInformation.size()) { //如果有语义错误
		cout << "************************Here are the semantic errors***********************" << endl;
		for (int i = 0; i < semanticErrorInformation.size(); i++)
			cout << semanticErrorInformation[i] << endl;
		cout << "********************Please correct your semantic errors********************" << endl;
	}
}