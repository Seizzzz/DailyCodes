#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class MergeMethod
{
public:
	int** table;
	int* temp;
	int record[100];
	int num;

	void output();
	void divide(int);
	void copy(int);
	void generate(int);

	MergeMethod(int);
};
