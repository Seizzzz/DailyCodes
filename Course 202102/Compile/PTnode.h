﻿/*
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

class Type{
public:
    string str;//终结符号的具体属性
    string token;//终结符号或非终结符号本身的名称
    int lineNumber;//终结符号的行号，参照语法分析指导.docx
    vector<Type*> children; //对应产生式下面的结点

    Type(){}
    Type(string typ, string name, int ln): str(typ), token(name), lineNumber(ln){}
    Type(string name, vector<Type*> cdn): token(name), children(cdn){}
};
#define YYSTYPE Type*

#endif