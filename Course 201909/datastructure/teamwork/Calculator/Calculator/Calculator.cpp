#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stack>
#include <cmath>
#include <iomanip>
using namespace std;

double cal_ans(string infix);

const char list_priority[8][8] = { //运算符优先级表
	//        +      -      *      /      ^      (      )      \0
	/*+*/    '>',   '>',   '<',   '<',   '<',   '<',   '>',   '>',
	/*-*/    '>',   '>',   '<',   '<',   '<',   '<',   '>',   '>',
	/***/    '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
	/*/*/    '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
	/*^*/    '>',   '>',   '>',   '>',   '>',   '<',   '>',   '>',
	/*(*/    '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
	/*)*/    ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',
	/*\0*/   '<',   '<',   '<',   '<',   '<',   '<',   ' ',   '=' };

void err()
{
	cout << "error" << endl;
	exit(-1);
}

double read_digit(char*& ptr)
{
	double ans;
	sscanf_s(ptr, "%lf", &ans); //在所给指针指向位置读入一个双浮点数 储存在ans中

	while (isdigit(*ptr) || *ptr == '.') ++ptr; //移动指针至该数字之后

	return ans;
}

int num_symbol(char a)
{
	switch (a) //将运算符转为数字 方便通过优先级表判断优先级
	{
		case '+': return 0;
		case '-': return 1;
		case '*': return 2;
		case '/': return 3;
		case '^': return 4;
		case '(': return 5;
		case ')': return 6;
		case '\0': return 7;
		default: err(); //未定义的运算符
	}
}

char cmp_priority(char stack, char now) //比较栈顶与当前运算符优先级大小
{
	unsigned int _stack = num_symbol(stack), _now = num_symbol(now);
	return list_priority[_stack][_now];
}

double cal_binary(double d1, char opt, double d2) //返回两数字在给定运算后的值
{
	switch (opt)
	{
		case '+': return d1 + d2;
		case '-': return d1 - d2;
		case '*': return d1 * d2;
		case '/': return d1 / d2;
		case '^': return pow(d1, d2);
		default: err();
	}
}

void cal_una(string& s, unsigned int sp) //unary 替换一元函数为数字
{
	char* ptr = &s[0] + sp;
	unsigned int ed = sp;
	while (*ptr != '(') {++ptr; ++ed;} //指向一元函数左括号
	++ptr; ++ed;
	unsigned int cnt = 1, st = ed;
	while (cnt != 0)
	{
		if (*ptr == '(') ++cnt;
		else if (*ptr == ')') --cnt;
		++ptr; ++ed;
	}

	stringstream ss_substr;
	string ans_substr;

	if (ed - st - 1 == 0) err(); //输入为空 判断输入异常

	if (s.find("sin", sp) != string::npos) ss_substr << sin(cal_ans(s.substr(st, ed - st - 1)));
	else if (s.find("cos", sp) != string::npos) ss_substr << cos(cal_ans(s.substr(st, ed - st - 1)));
	else if (s.find("ln", sp) != string::npos) ss_substr << log(cal_ans(s.substr(st, ed - st - 1)));
	else if (s.find("log", sp) != string::npos) ss_substr << log10(cal_ans(s.substr(st, ed - st - 1)));
	else err();

	ss_substr >> ans_substr; //数字转为字符串
	if (ans_substr == "") err(); //计算结果为空 判断输入异常
	s.replace(sp, ed - sp, ans_substr);

	return;
}

void cal_bin(string& s, unsigned int sp) //binary 二元函数
{
	return;
}

double cal_ans(string infix) //将表达式字符串替换为数字
{
	stack<double> digit;
	stack<char> symbol;
	symbol.push('\0');

	unsigned int special;
	while ((special = infix.find("sin(")) != string::npos) cal_una(infix,special);
	while ((special = infix.find("cos(")) != string::npos) cal_una(infix, special);
	while ((special = infix.find("ln(")) != string::npos) cal_una(infix, special);
	while ((special = infix.find("log(")) != string::npos) cal_una(infix, special); //log()理解为lg()

	char* ptr = &infix[0];
	while (!symbol.empty())
	{
		if (isdigit(*ptr)) digit.push(read_digit(ptr));
		else
		{
			switch (cmp_priority(symbol.top(), *ptr))
			{
			case '<': {
				symbol.push(*(ptr++)); //将更优先运算符压入 并向后移动指针
				break;
			}
			case '>': { //栈顶运算符优先度更高 可实行之前的计算
				char operat = symbol.top(); symbol.pop();
				double digit1 = digit.top(); digit.pop();
				double digit2 = digit.top(); digit.pop();
				digit.push(cal_binary(digit2, operat, digit1));
				break;
			}
			case '=': { //当且仅当右括号遇到左括号 将左括号弹出即可
				symbol.pop();
				++ptr;
				break;
			}
			default: err(); //未定义的优先级
			}
		}
	}

	return digit.top(); //返回计算完毕后剩下的数字 即该表达式字符串的结果
}

void erase_space(string& s) //忽略空格 增强鲁棒性
{
	unsigned int pos = 0;
	while ((pos = s.find(" ", pos)) != string::npos) s.erase(pos, 1);

	return;
}

void formatize(string& s) //将表达式格式化为可处理的形式
{
	erase_space(s);
	s.erase(s.find("="), 1);

	return;
}

int main()
{
	string infix;
	getline(cin, infix);
	formatize(infix);

	cout << setprecision(4) << fixed << cal_ans(infix); //输出保留小数点后四位

	return 0;
}
