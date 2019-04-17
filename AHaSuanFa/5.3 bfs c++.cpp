#include <bits/stdc++.h>
#define maxn 20
using namespace std;

int start,end,city,road;
int info[maxn][maxn];
bool vis[maxn];

/*
5 7 0 4
1 2
1 3
2 3
2 4
3 4
3 5
4 5
*/

struct element
{
	int x;
	int step;
}que[maxn*maxn];

int main()
{
	cin >> city >> road >> start >> end;
	memset(vis,true,sizeof(vis));
	for(int i=0;i<city;i++)
		for(int j=0;j<city;j++) info[i][j]=999; //infinite
	int bufa,bufb;
	for(int i=0;i<road;i++)
	{
		cin >> bufa >> bufb;
		info[bufa-1][bufb-1]=1;
		info[bufb-1][bufa-1]=1;
	}
	//initialized
	int head=0,tail=1;
	
	que[head].x=start;
	que[head].step=0;
	vis[start]=false;
	
	bool flag=false;
	while(head<tail)
	{
		int now=que[head].x;
		for(int i=0;i<city;i++)
		{
			if(info[now][i]!=999 && vis[i])
			{
				que[tail].x=i;
				que[tail].step=que[head].step+info[now][i];
				tail++;
				vis[i]=false;
			}
			
			if(que[tail-1].x==end)
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

