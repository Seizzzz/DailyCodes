#pragma once
#include <iostream>

using namespace std;

class ExhaustMethod
{
public:
	int** table;
	int* record;
	int num;
	bool solved = false;
	int day;

	void output();
	bool check(int, int);
	void dfs(int, int);
	ExhaustMethod(int);
	~ExhaustMethod();
};
