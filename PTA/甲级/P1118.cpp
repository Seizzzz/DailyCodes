#include <bits/stdc++.h>
using namespace std;

int n,sum;
int dp[13][13];
int temp[13];
bool vis[13];

void dfs(int have,int now)
{
	if(have==n)
	{
		if(now==sum)
		{
			for(int i=0;i<n;i++) cout << temp[i] << " ";
			cout << endl;
			exit(0);
		} 
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			vis[i]=false;
			temp[have]=i;
			dfs(have+1,now+i*dp[n][have+1]);
			vis[i]=true;
		}
	}
	
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> sum;
	
	for(int i=1;i<=n;i++) vis[i]=true;
	
	dp[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}
	
	dfs(0,0);

	return 0;
}

