#include <bits/stdc++.h>
#define height 5
#define length 4
#define maxn height //height>length
using namespace std;

int myx,myy,endx,endy;
bool a[maxn][maxn],book[maxn][maxn];
int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

void init()
{
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++) a[i][j]=false;
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++) book[i][j]=false;
	return;
}

struct note
{
	int x;
	int y;
	int step;
}que[height*length+1];

int main()
{
	init();

	cin >> myx >> myy;
	cin >> endx >> endy;
	
	int obstacle;
	cin >> obstacle;
	while(obstacle--)
	{
		int bufx,bufy;
		cin >> bufx >> bufy;
		a[bufx][bufy]=true;
	}
	
	//
	int head=1,tail=1;
	
	que[tail].x=myx;
	que[tail].y=myy;
	que[tail].step=0;
	tail++;
	
	book[myx][myy]=true;
	
	bool flag=false;
	int tx,ty;
	
	while(head<tail)
	{
		for(int k=0;k<4;k++)
		{
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			
			if(tx<0 || tx>=length || ty<0 || ty>=height) continue;
			
			if(!a[tx][ty] && !book[tx][ty])
			{
				book[tx][ty]=true;
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].step=que[head].step+1;
				tail++;
			}
			if(tx==endx && ty==endy)
			{
				flag=true;
				break;
			}
		}
		if(flag) break;
		head++;
	}
	
	cout << que[tail-1].step << endl;
	

	return 0;
}

