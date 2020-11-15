#pragma once

#include <iostream>

using namespace std;

class RotateMethod
{
public:
	int** table;
	int** wheel;
	int num;
	int pair;

	void rotate();
	void record(int);

	void output();
	
	RotateMethod(int);
	~RotateMethod();
};
