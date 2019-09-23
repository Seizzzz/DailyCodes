#include <bits/stdc++.h>
using namespace std;

string n1,n2;
int tag,radix;

long long input(string num,int radix)
{
	long long ans=0;
	for(int i=num.length()-1;i>=0;--i)
	{
		long long now = (isdigit(num[i]))? num[i]-'0':num[i]-'a'+10;
		ans += now * (long long)pow(radix,num.length()-i-1);
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	/*
	while(true)
	{
		cin >> n1 >> radix;
		cout << input(n1,radix) << endl;
	}*/
	
	cin >> n1 >> n2;
	cin >> tag >> radix;
	
	if(tag==2) swap(n1,n2);
	long long num1 = input(n1,radix);
	
	long long minval=2,maxval=50;
	while(minval < maxval)
	{
		long long mid = (minval + maxval) >> 1;
		if(input(n2,mid) < num1) minval = mid;
		else maxval = mid;
	}
	
	if(minval==maxval && input(n2,minval)!=num1) cout << "Impossible" << endl;
	else cout << minval << endl;

	return 0;
}

