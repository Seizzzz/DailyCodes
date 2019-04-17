#include <bits/stdc++.h>
using namespace std;

int t,m;
int dp[100002];
int tim[10002],value[10002];

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> t >> m;
	
	for(int i=1;i<=m;i++) cin >> tim[i] >> value[i];
	
	for(int i=1;i<=m;i++)
	{
		for(int j=tim[i];j<=t;j++)
		{
			dp[j]=max(dp[j],dp[j-tim[i]]+value[i]);
		}
	}
	
	int max=0;
	for(int i=0;i<=t;i++) if(max<dp[i]) max=dp[i];
	
	cout << max << endl;

	return 0;
}

