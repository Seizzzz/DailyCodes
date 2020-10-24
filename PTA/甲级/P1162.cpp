#include <bits/stdc++.h>
#define maxn 32 
using namespace std;

int mymap[maxn][maxn];
bool vis[maxn][maxn];
int size;

int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

struct node
{
	int x;
	int y;
}que[maxn*maxn];

void bfs(int myx,int myy)
{
	if(!vis[myx][myy] || mymap[myx][myy]==1) return;
	
	vis[myx][myy]=false;
	int head=0,tail=1;
	que[head].x=myx;
	que[head].y=myy;
	
	while(head<tail)
	{
		for(int k=0;k<4;k++)
		{
			int tx=que[head].x+next[k][0];
			int ty=que[head].y+next[k][1];
			
			if(tx<0 || ty<0 || tx>=size || ty>=size || !vis[tx][ty] || mymap[tx][ty]==1) continue;
			
			vis[tx][ty]=false;
			que[tail].x=tx;
			que[tail].y=ty;
			tail++;
		}
		head++;
	}
}

int main()
{
	cin >> size;
	
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++) cin >> mymap[i][j];
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++) vis[i][j]=true;
	//initialized
	
	for(int i=0;i<size;i++) bfs(0,i);
	for(int i=0;i<size;i++) bfs(size-1,i);
	for(int i=0;i<size;i++) bfs(i,0);
	for(int i=0;i<size;i++) bfs(i,size-1);
	
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(mymap[i][j]==0)
			{
				if(!vis[i][j]) cout << "0 ";
				else cout << "2 ";
			}
			else cout << "1 ";
		}
		cout << endl;
	}
	
	return 0;
}

