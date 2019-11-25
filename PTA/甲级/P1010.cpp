#include <bits/stdc++.h>
using namespace std;

string n1,n2;
int tag,radix;

long long input(string s,int radix)
{
	long long ans=0;
	for(int i=0;i<s.length();++i)
	{
		ans = ans*radix + ((isdigit(s[i]))? s[i]-'0':s[i]-'a'+10);
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	cin >> n1 >> n2;
	cin >> tag >> radix;
	
	if(tag==2) swap(n1,n2);
	
	if(n1 == n2)
	{
		cout << radix << endl;
		exit(0);
	}
	
	long long num1 = input(n1,radix);
	
	long long minval=2,maxval=35;
	while(minval < maxval)
	{
		long long mid = (minval + maxval) >> 1;
		long long trial = input(n2,mid);
		if(trial == num1)
		{
			cout << mid << endl;
			exit(0);
		}
		else if(trial < num1) minval = mid;
		else maxval = mid;
	}
	
	cout << "Impossible" << endl;

	return 0;
}

