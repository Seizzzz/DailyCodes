#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	Vector<int> ex;
	ex[0]=0;
	ex[1]=1;
	cout << ex[0] << ex[1];
	
	ex[0]=1;
	ex[1]=2;
	cout << ex[0] << ex[1];

	return 0;
}

