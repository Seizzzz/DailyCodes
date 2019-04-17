#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

/*
9 10
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 1 0
7 2 7 3 S
*/

struct node
{
	int x;
	int y;
	char direction; //1东 2南 3西 4北 
	int time;
}que[10000000];

int mymap[52][52];
int n,m;
int endx,endy;
int ans=INF;
int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char nextdirection[4]={'E','S','W','N'};
int vis[52][52];

bool judgearound(struct node a)
{
	if(a.time>=vis[a.x][a.y+1] && a.time>=vis[a.x+1][a.y] && a.time>=vis[a.x][a.y-1] && a.time>=vis[a.x-1][a.y]) return true;
	return false;
}

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) cin >> mymap[i][j];
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) vis[i][j]=INF;
	
	cin >> que[0].x >> que[0].y;
	cin >> endx >> endy;
	cin >> que[0].direction;
	
	int head=0,tail=1;
	while(head<tail)
	{
		if(que[head].time<vis[que[head].x][que[head].y])
		{
			vis[que[head].x][que[head].y]=que[head].time;
		}
		else if(judgearound(que[head])) //四周都小于该位置状态 可舍 
		{
			head++;
			continue;
		}
		
		if(que[head].x==endx && que[head].y==endy && que[head].time<ans)
		{
			ans=que[head].time;
			head++;
			continue;
		}
		
		for(int k=0;k<4;k++)
		{
			if(nextdirection[k]==que[head].direction);
			else
			{
				que[tail].x=que[head].x;
				que[tail].y=que[head].y;
				que[tail].direction=nextdirection[k];
				que[tail].time=que[head].time+1;
				tail++;
			}
		}
		
		int k;
		if(que[head].direction=='E') k=0;
		else if(que[head].direction=='S') k=1;
		else if(que[head].direction=='W') k=2;
		else k=3;
		
		for(int step=1;step<=3;step++)
		{
			int tx=que[head].x+(step*next[k][0]);
			int ty=que[head].y+(step*next[k][1]);
			if(tx>=1 && ty>=1 && tx<=n && ty<=m && !mymap[tx][ty] && que[head].time+1<vis[tx][ty])
			{
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].direction=que[head].direction;
				que[tail].time=que[head].time+1;
				//vis[tx][ty]=que[head].time+1;
				tail++;
			}
		}		
		head++;
	}
	
	if(ans==INF) cout << "-1" << endl;
	else cout << ans << endl;
	

	return 0;
}

