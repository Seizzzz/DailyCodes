#include <bits/stdc++.h>
using namespace std;

int number;

void prnt(int n)
{
	if(n==0){
		cout << "0";
		return;
	}
	if(n==1){
		cout << "2(0)";
		return;
	}
	if(n==2){
		cout << "2";
		return;
	}
	
	int wei=0;
	while((1<<wei) <= n) wei++; //ȡ1,2,4,8...
	wei--;
	if(wei!=1)
	{
		cout << "2(";
		prnt(wei);
		cout << ")";
	} 
	else cout << "2";
	
	int rest=n-(1<<wei);
	if(rest)
	{
		cout << "+";
		prnt(rest);
	}
	
}

int main()
{
	cin >> number;
	
	prnt(number);
	cout << endl;

	return 0;
}

