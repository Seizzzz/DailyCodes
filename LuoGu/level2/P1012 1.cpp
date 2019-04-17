#include <bits/stdc++.h>
using namespace std;

string num[25];

bool cmp(string a,string b)
{
	return a+b>b+a;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> num[i];
	
	sort(num,num+n,cmp);
	
	for(int i=0;i<n;i++) cout << num[i];
	cout << endl;

	return 0;
}

