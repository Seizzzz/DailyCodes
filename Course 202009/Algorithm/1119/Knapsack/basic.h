#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BasicMethod
{
public:
	int** dp;
	int capacity;
	int number;
	int* weight;
	int* value;

	int sol();
	void printItems();
	
	BasicMethod(int, int, int*, int*);
	~BasicMethod();
};