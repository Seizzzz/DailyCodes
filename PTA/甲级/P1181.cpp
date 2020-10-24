#include <bits/stdc++.h>
using namespace std;

int num[100005];

int main()
{
	int n,m;
	cin >> n >> m;
	
	for(int i=0;i<n;i++) cin >> num[i];
	
	long long now=0;
	int divide=0;
	for(int i=0;;)
	{
		while(now<=m)
		{
			if(i<n)
			{
				now+=num[i];
				i++;
			}
			else
			{
				cout << divide+1 << endl;
				return 0;
			}
		}
		i--;
		
		now=0;
		divide++;
	}
	
	

	return 0;
}

