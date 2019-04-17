#include <bits/stdc++.h>
#define maxn 20
using namespace std;

/*
5 8 0 4
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3
*/

int minans=999,start,end,city,road;
int info[maxn][maxn];
bool vis[maxn];

void dfs(int now,int dis)
{
	if(dis>minans) return;
	if(now==end)
	{
		if(dis<minans) minans=dis;
		return;
	}
	
	for(int i=0;i<city;i++)
	{
		if(info[now][i]!=999 && vis[i])
		{
			vis[i]=false;
			dfs(i,dis+info[now][i]);
			vis[i]=true;
		}
	}
	
	return;
}

int main()
{
	cin >> city >> road >> start >> end;

	for(int i=0;i<city;i++)
		for(int j=0;j<city;j++) info[i][j]=999; //infinite
	memset(vis,true,sizeof(vis));
	
	int bufa,bufb;
	for(int i=0;i<road;i++)
	{
		cin >> bufa >> bufb;
		cin >> info[bufa-1][bufb-1];
	}
	//initialized
	vis[start]=false;
	dfs(start,0);
	
	cout << minans <<endl;
	
	
	return 0;
}

