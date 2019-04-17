#include <bits/stdc++.h>
#define maxn 6
using namespace std;

int info[maxn][maxn];
/*
9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
*/
int main()
{
	int n,dis[maxn];
	bool vis[maxn];
	memset(vis,true,sizeof(vis));
	
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++) info[i][j]=999;
	
	cin >> n;
	int bufa,bufb;
	while(n--)
	{
		cin >> bufa >> bufb;
		cin >> info[bufa-1][bufb-1];
	}
	info[0][0]=0;
	for(int i=0;i<maxn;i++) dis[i]=info[0][i];
	//initialized
	
	vis[0]=false;
	
	int mindis,minpos;
	for(int i=0;i<maxn;i++)
	{
		mindis=999;
		for(int j=0;j<maxn;j++)
		{
			if(dis[j]<mindis && vis[j])
			{
				mindis=dis[j];
				minpos=j;
			}
		}
		vis[minpos]=false;
		
		for(int k=0;k<maxn;k++)
		{
			if(info[minpos][k]<999)
			{
				if(dis[minpos]+info[minpos][k]<dis[k]) dis[k]=dis[minpos]+info[minpos][k];
			}
		}
	}
	
	for(int i=0;i<maxn;i++) cout << dis[i] << " ";
	cout << endl;
	
	return 0;
}

