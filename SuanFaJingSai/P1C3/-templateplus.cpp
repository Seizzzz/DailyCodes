#include <iostream>
#include <cstdio>
using namespace std;

template<typename T>
T sum(T num1,T num2)
{
	T ans= num1 + num2;
	return ans;
}

int main()
{
	double a,b;
	
	cin >> a >> b;
	
	cout << sum(a,b) << endl;

	return 0;
}
