#include <bits/stdc++.h>
using namespace std;

int m,n;
int dp[102][10002];

int dish[102];

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	
	for(int i=0;i<=100;i++)
		for(int j=0;j<=10000;j++) dp[i][j]=0;
	for(int i=1;i<=n;i++) cin >> dish[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j<dish[i]) dp[i][j]=dp[i-1][j];
			else if(j==dish[i]) dp[i][j]=dp[i-1][j]+1;
			else dp[i][j]=dp[i-1][j-dish[i]]+dp[i-1][j];
		}
	}
	
	cout << dp[n][m] << endl;
	return 0;
}

