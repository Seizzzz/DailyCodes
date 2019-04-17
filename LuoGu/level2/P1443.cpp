#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int mymap[404][404];
int n,m;
int next[8][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};

struct node
{
	int x;
	int y;
	int step;
}que[160001];

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) mymap[i][j]=INF;
	
	int head=0,tail=1;
	cin >> que[0].x >> que[0].y;
	que[0].step=0;
	mymap[que[0].x][que[0].y]=0;
	
	while(head<tail)
	{
		for(int k=0;k<8;k++)
		{
			int tx=que[head].x+next[k][0];
			int ty=que[head].y+next[k][1];
			if(tx>=1 && ty>=1 && tx<=n && ty<=m && mymap[tx][ty]>que[head].step+1)
			{
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].step=que[head].step+1;
				mymap[tx][ty]=que[head].step+1;
				tail++;
			}
		}
		head++;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mymap[i][j]==INF) printf("%-5d",-1); //有时候洛谷的题真的质量太低，我想知道这有什么意义 
			else printf("%-5d",mymap[i][j]);
		}
		cout << endl;
	}

	return 0;
}

