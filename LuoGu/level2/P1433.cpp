#include <bits/stdc++.h>
using namespace std;

int n;
double dis[16][16],ans=99999999;

double cheese[16][2];
inline double cal_dis(int a,int b)
{
	return sqrt(pow((cheese[a][0]-cheese[b][0]),2)+pow((cheese[a][1]-cheese[b][1]),2));
}

bool vis[16];
inline void dfs(double now,int have,int point)
{
	if(now>=ans) return;
	
	if(have==n)
	{
		if(now<ans) ans=now;
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			vis[i]=false;
			dfs(now+dis[point][i],have+1,i);
			vis[i]=true;
		}
	}
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> cheese[i][0] >> cheese[i][1];
		vis[i]=true;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			dis[i][j]=cal_dis(i,j);
			dis[j][i]=dis[i][j];
			dis[i][i]=0;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		vis[i]=false;
		dfs(sqrt(pow(cheese[i][0],2)+pow(cheese[i][1],2)),1,i);
		vis[i]=true;
	}
	
	cout << fixed << setprecision(2) << ans << endl;

	return 0;
}

