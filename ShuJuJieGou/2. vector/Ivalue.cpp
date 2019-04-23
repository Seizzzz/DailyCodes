#include <bits/stdc++.h>
using namespace std;

vector<int> myint;

/*
Sumamry:
早期C：左值可在赋值运算符的左右，右值只能在右侧 
	   左值是一个表达式，表示某个变量或对象的内存位置，并且能够用&取其地址
	   若一个表达式不是左值，即是右值 

常见的引用均为左值引用
	e.g. string s;  string& ref_s=s;
	值得注意的是，普通左值引用不能赋值为一个右值（不严谨地讲，也许右值没有一个地址） 
	e.g. string& s=string("example");
	而若以cv限定符定义左值引用时(const,volatile)，便可以一个右值对其进行赋值 
	e.g. typename function(const string& ref_s);
	
c++ 11 右值引用
更方便的对右值进行引用，待补 
*/

int main()
{
	std::ios::sync_with_stdio(false);
	
	int i = 42;
	i = 43; 
	int* p = &i; // ok, i 是左值
	int& foo();
	foo() = 42; // ok, foo() 是左值
	int* p1 = &foo(); // ok, foo() 是左值
	
	int foobar();
	int j = 0;
	j = foobar(); // ok, foobar() 是右值
	//int* p2 = &foobar(); // 错误，不能获取右值的地址
	j = 42; // ok, 42 是右值

	return 0;
}

