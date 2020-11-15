#include "exhasut.h"

void ExhaustMethod::output()
{
	if(!solved)
	{
		cout << "NOT FOUND" << endl;
		return;
	}
	
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			cout << table[i][j] + 1 << " ";
		}
		cout << endl;
	}
}

bool ExhaustMethod::check(int line, int col)
{
	for (int i = 0; i < num; ++i) record[i] = 0;
	for (int i = 0; i <= line; ++i) ++record[table[i][col]];
	for (int i = 0; i < num; ++i)
		if (record[i] > 1) return false;

	for (int i = 0; i < num; ++i) record[i] = 0;
	for (int j = 0; j <= col; ++j) ++record[table[line][j]];
	for (int i = 0; i < num; ++i)
		if (record[i] > 1) return false;

	return true;
}

void ExhaustMethod::dfs(int i, int j)
{
	if (i == num)
	{
		solved = true;
		return;
	}

	for (int k = 0; k < num; ++k)
	{
		if (solved) return;
		table[i][j] = k;
		if (check(i, j))
		{
			if (j + 1 == num) dfs(i + 1, 0);
			else dfs(i, j + 1);
		}
	}
}

ExhaustMethod::ExhaustMethod(int n): num(n)
{
	if (n % 2) day = n;
	else day = n - 1;
	
	table = new int* [n + 1];
	for (int i = 0; i < n + 1; ++i) table[i] = new int[n + 1];
	record = new int[n + 1];

	for (int i = 0; i < n + 1; ++i)
	{
		for (int j = 0; j < n + 1; ++j)
		{
			table[i][j] = -1;
		}
	}

	dfs(0, 0);
}

ExhaustMethod::~ExhaustMethod()
{
	for (int i = 0; i < num + 1; ++i) delete[] table[i];
	delete[] table;
}
