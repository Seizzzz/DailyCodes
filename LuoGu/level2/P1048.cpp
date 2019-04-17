#include <bits/stdc++.h>
using namespace std;

int t,m;
int dp[102][1002];
int money[102],tim[1002];

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> t >> m;
	
	for(int i=1;i<=m;i++) cin >> tim[i] >> money[i];
	
	for(int i=1;i<=m;i++)
	{
		for(int j=t;j;j--)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=tim[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-tim[i]]+money[i]);
		}
	}
	
	cout << dp[m][t] << endl;

	return 0;
}

