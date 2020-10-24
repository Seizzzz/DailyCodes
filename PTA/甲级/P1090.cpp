#include <bits/stdc++.h>
using namespace std;

int info[10005];
int n;

void refresh(int a)
{
	for(;a<n;a++)
	{
		if(info[a]<info[a-1]) swap(info[a],info[a-1]);
		else return;
	}
	return;
}

int main()
{
	cin >> n;
	
	for(int i=0;i<n;i++) cin >> info[i];
	
	sort(info,info+n);
	
	int sum=0;
	
	for(int i=1;i<n;i++)
	{
		sum=sum+ info[i]+info[i-1];
		info[i]+=info[i-1];
		refresh(i+1);
	}
	
	cout << sum << endl;

	return 0;
}

