#include <bits/stdc++.h>
using namespace std;

int size,n;
int weight[32];
int dp[32][20002];

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> size >> n;
	
	for(int i=1;i<=n;i++) cin >> weight[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=size;j>=0;j--)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=weight[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-weight[i]]+weight[i]);
		}
	}
	
	cout << size-dp[n][size] << endl;

	return 0;
}

