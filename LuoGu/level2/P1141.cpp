#include <bits/stdc++.h>
using namespace std;

char mymap[1005][1005];
bool vis[1005][1005];
int n,m,ans;
int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int anslist[1005][1005];

struct node
{
	int x;
	int y;
}que[1000005];

void dfs(int x,int y)
{
	ans++;
	que[ans].x=x;
	que[ans].y=y;
	
	for(int k=0;k<4;k++)
	{
		int tx=x+next[k][0],ty=y+next[k][1];
		if(tx>=1 && ty>=1 && tx<=n && ty<=n && vis[tx][ty] && mymap[tx][ty]!=mymap[x][y])
		{
			vis[tx][ty]=false;
			dfs(tx,ty);
		}
	}
	return;
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) vis[i][j]=true;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) cin >> mymap[i][j];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(vis[i][j])
			{
				ans=0;
				//que[ans].x=i;
				//que[ans].y=j;
				vis[i][j]=false;
				dfs(i,j);
				for(int ha=1;ha<=ans;ha++) anslist[que[ha].x][que[ha].y]=ans;
			}
		}
	}
	
	while(m--)
	{
		int bufx,bufy;
		cin >> bufx >> bufy;
		cout << anslist[bufx][bufy] << endl;
	}

	return 0;
}

