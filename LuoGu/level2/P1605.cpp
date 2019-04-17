#include <bits/stdc++.h>
using namespace std;

/*
2 2 1
1 1 2 2
1 2
*/

bool mymap[20][5];
int n,m,t,sx,sy,fx,fy;
int ans=0;

void init()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) mymap[i][j]=true;
}

void dfs(int myx,int myy)
{
	if(!mymap[myx][myy]) return;
	if(myx<0 || myy<0 || myx>=n || myy>=m) return;
	
	mymap[myx][myy]=false;
	if(myx==fx && myy==fy)
	{
		ans++;
		mymap[myx][myy]=true;
		return;
	}
	
	dfs(myx,myy+1);
	dfs(myx+1,myy);
	dfs(myx,myy-1);
	dfs(myx-1,myy);
	
	mymap[myx][myy]=true;
	return;
}

int main()
{
	cin >> n >> m >> t >> sx >> sy >> fx >> fy;
	sx--;sy--;fx--;fy--;
	init();
	while(t--)
	{
		int bufx,bufy;
		cin >> bufx >> bufy;
		bufx--;bufy--;
		mymap[bufx][bufy]=false;
	}
	//initialized
	
	dfs(sx,sy);
	
	cout << ans << endl;

	return 0;
}

