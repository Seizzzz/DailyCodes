#include <bits/stdc++.h>
#define ll long long
#define INF 2147483647
using namespace std;
/*
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4
*/
ll mymap[10005][10005];
ll dis[10005];
bool vis[10005];

int point,edge,start;

int main()
{
	cin >> point >> edge >> start;
	
	for(int i=1;i<=point;i++)
		for(int j=1;j<=point;j++) mymap[i][j]=INF;
	for(int i=1;i<=point;i++) mymap[i][i]=0;
	for(int i=1;i<=point;i++) vis[i]=true;
	
	int temp=edge,buf1,buf2,buf3;
	while(temp--)
	{
		cin >> buf1 >> buf2 >> buf3;
		mymap[buf1][buf2]=buf3;
	}
	for(int i=0;i<=point;i++) dis[i]=mymap[start][i];
	//initialized
	
	int mindis,minpos;
	for(int i=1;i<=point;i++)
	{
		mindis=INF;
		for(int j=1;j<=point;j++)
		{
			if(dis[j]<mindis && vis[j])
			{
				mindis=dis[j];
				minpos=j;
			}
		}
		vis[minpos]=false;
		
		for(int k=1;k<=point;k++)
		{
			if(mymap[minpos][k]<INF)
			{
				if(dis[minpos]+mymap[minpos][k]<dis[k]) dis[k]=dis[minpos]+mymap[minpos][k];
			}
		}
	}
	
	for(int i=1;i<=point;i++) cout << dis[i] << " ";
	cout << endl;
	
	return 0;
}

