#include <bits/stdc++.h>
#define length 10
#define height 10
using namespace std;

/*
5 7
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
*/

int mymap[length+1][height+1];
int myx,myy;
bool vis[length+1][height+1];

void init()
{
	for(int i=0;i<height;i++)
		for(int j=0;j<length;j++) vis[i][j]=false;
}

int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

struct node
{
	int x;
	int y;
}que[length*height+1];

int main()
{
	init();
	cin >> myx >> myy;
	for(int i=0;i<height;i++)
		for(int j=0;j<length;j++) cin >> mymap[i][j];
		
	int head=1,tail=2;
	que[head].x=myx;
	que[head].y=myy;
	vis[myx][myy]=true;
	
	int area=1;
	
	while(head<tail)
	{
		for(int k=0;k<4;k++)
		{
			int tx=que[head].x+next[k][0];
			int ty=que[head].y+next[k][1];
			
			if(tx<0 || ty<0 || tx>=height || ty>=length) continue;
			
			//cout << tx << " " << ty << " " << mymap[tx][ty];
			if(!vis[tx][ty] && mymap[tx][ty])
			{
				area++;
				vis[tx][ty]=true;
				que[tail].x=tx;
				que[tail].y=ty;
				tail++;
			}
		}
		head++;
	}
	
	cout << area << endl;

	return 0;
}

