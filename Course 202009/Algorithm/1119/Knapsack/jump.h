#pragma once
#include <iostream>
#include <vector>
using namespace std;

class JumpMethod
{
public:
	struct node
	{
		double w;
		double v;
		node(double weight, double value) : w(weight), v(value) {}
	};
	
	int number, capacity;
	double* value;
	double* weight;
	vector<node*> p;
	vector<int> first;

	bool equal(double a, double b);
	double sol();
	void printItems();
	
	JumpMethod(int, int, double*, double*);
	~JumpMethod();
};