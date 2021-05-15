/*
������
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
int errorBound = int(1e9 + 7); //Ĭ�ϴ������ޣ�INF

void preProcess(string inName);
string char2str(char* chs);
bool chs2int(char* chs, int &num);
void dfsPT(Type* now); //������ͨ�﷨������
void outputErrors();

int main(int argc, char **argv){
	const string inFile = "code.pas"; //Ĭ�������ļ���
	const string outFile = "code.c"; //Ĭ������ļ���

	preProcess(inFile); //Ԥ����

	FILE* fp;
	errno_t err = fopen_s(&fp, inFile.c_str(), "r");
	if (err) return -1;
	yyin = fp;
	yyparse(); //�����﷨��������
	fclose(fp);

	cout << "Lexical Analyzed" << endl;
	cout << "Syntax Analyzed" << endl;
	
	//dfsPT(ParseTreeHead);
	if (!lexicalErrorInformation.empty() || !syntaxErrorInformation.empty()) //����дʷ����﷨����
	{
		outputErrors();
		return 0;
	}

	//�������
	_Program* ASTRoot = getProgram(ParseTreeHead);
	SemanticAnalyse(ASTRoot);//�������

	if (!semanticErrorInformation.empty()) //������������
	{
		outputErrors();
		return 0;
	}
	cout << "Semantic Analyzed" << endl;

	//��������
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

//��ͨ�﷨����debug��Ϣ�����������
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