/*
主头文件
*/
#ifndef PTNODE_H
#define PTNODE_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

//重新定义属性类型(yylval实际上应由yacc定义)c
class Type {
public:
	string str;//具体属性
	string token;//本身的名称
	int lineNumber;//终结符号的行号
	vector<Type*> children;

	Type() {}
	Type(string typ, string name, int ln) : str(typ), token(name), lineNumber(ln) {}
	Type(string name, vector<Type*> cdn) : token(name), children(cdn) {}
};
#define YYSTYPE Type*

#endif