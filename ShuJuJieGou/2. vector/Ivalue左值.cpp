#include <bits/stdc++.h>
using namespace std;

vector<int> myint;

/*
Sumamry:
����C����ֵ���ڸ�ֵ����������ң���ֵֻ�����Ҳ� 
	   ��ֵ��һ�����ʽ����ʾĳ�������������ڴ�λ�ã������ܹ���&ȡ���ַ
	   ��һ�����ʽ������ֵ��������ֵ 

���������þ�Ϊ��ֵ����
	e.g. string s;  string& ref_s=s;
	ֵ��ע����ǣ���ͨ��ֵ���ò��ܸ�ֵΪһ����ֵ�����Ͻ��ؽ���Ҳ����ֵû��һ����ַ�� 
	e.g. string& s=string("example");
	������cv�޶���������ֵ����ʱ(const,volatile)�������һ����ֵ������и�ֵ 
	e.g. typename function(const string& ref_s);
	
c++ 11 ��ֵ����
������Ķ���ֵ�������ã����� 
*/

int main()
{
	std::ios::sync_with_stdio(false);
	
	int i = 42;
	i = 43; 
	int* p = &i; // ok, i ����ֵ
	int& foo();
	foo() = 42; // ok, foo() ����ֵ
	int* p1 = &foo(); // ok, foo() ����ֵ
	
	int foobar();
	int j = 0;
	j = foobar(); // ok, foobar() ����ֵ
	//int* p2 = &foobar(); // ���󣬲��ܻ�ȡ��ֵ�ĵ�ַ
	j = 42; // ok, 42 ����ֵ

	return 0;
}

