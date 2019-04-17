#include <bits/stdc++.h>
using namespace std;

int money,total;
int dp[25][30000];
int price[25],value[25];


int main()
{
	std::ios::sync_with_stdio(false);
	
	cin >> money >> total;
	for(int i=1;i<=total;i++) cin >> price[i] >> value[i];
	
	for(int i=0;i<total;i++)
		for(int j=0;j<money;j++) dp[i][j]=0;
	
	for(int i=1;i<=total;i++)
	{
		int delta=price[i]*value[i];
		for(int j=1;j<=money;j++)
		{
			if(j<price[i]) dp[i][j]=dp[i-1][j]; //vital!!!
			else dp[i][j]=max(dp[i-1][j-price[i]]+delta,dp[i-1][j]);
		}
	}
	
	cout << dp[total][money] << endl;

	return 0;
}

