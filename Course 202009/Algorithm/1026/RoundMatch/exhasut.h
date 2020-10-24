#pragma once
#include <iostream>

using namespace std;

class ExhaustMethod
{
public:
	int table[100][100];
	int record[100];
	int num;
	bool solved = false;

	void output();
	bool check(int, int);
	void dfs(int, int);
	ExhaustMethod(int);
};
