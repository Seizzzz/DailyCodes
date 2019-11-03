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
		if(now >= radix) return 0;
		ans += now * (long long)pow(radix,num.length()-i-1);
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n1 >> n2;
	cin >> tag >> radix;
	
	if(tag==2) swap(n1,n2);
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

