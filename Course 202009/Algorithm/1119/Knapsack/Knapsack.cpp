#include <iostream>
#include "basic.h"
#include "jump.h"
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int number;
	double capacity;
	cin >> number >> capacity;
	double* w = new double[number + 1];
	double* v = new double[number + 1];
	for (int i = 1; i <= number; ++i) cin >> w[i];
	for (int i = 1; i <= number; ++i) cin >> v[i];
	JumpMethod sol(number, capacity, w, v);
	
	//int number;
	//int capacity;
	//cin >> number >> capacity;
	//int* w = new int[number + 1];
	//int* v = new int[number + 1];
	//for (int i = 1; i <= number; ++i) cin >> w[i];
	//for (int i = 1; i <= number; ++i) cin >> v[i];
	//BasicMethod sol(number, capacity, w, v);

	delete[] w;
	delete[] v;

	return 0;
}