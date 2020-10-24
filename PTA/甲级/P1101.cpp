#include <bits/stdc++.h>
#define maxn 101
using namespace std;

char target[8]="yizhong";

char word[maxn][maxn];
bool vis[maxn][maxn];

int n;
int next[8][2]={{0,1},{-1,1},{-1,0},{-1,-1},{1,1},{1,0},{1,-1},{0,-1}};

void dfs(int x,int y,int step,int direction,bool changable)
{
	if(step==7)
	{
		int bufx=x,bufy=y;
		for(int i=0;i<7;i++)
		{
			bufx+=next[7-direction][0];
			bufy+=next[7-direction][1];
			vis[bufx][bufy]=true;
		}
		return;
	}
	if(x<0 || y<0 || x>=n || y>=n) return;
	
	if(word[x][y]==target[step])
	{
		if(changable) for(int i=0;i<8;i++) dfs(x+next[i][0],y+next[i][1],step+1,i,false);
		else dfs(x+next[direction][0],y+next[direction][1],step+1,direction,false);
	}
	
	return;
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++) cin >> word[i];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) vis[i][j]=false;
	//initialized
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) dfs(i,j,0,0,true);
	//calculated
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(vis[i][j]) cout << word[i][j];
			else cout << "*";
		}
		cout << endl;
	}
	//printed

	return 0;
}

