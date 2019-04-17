#include <bits/stdc++.h>
#define maxn 13
using namespace std;

/*
3 3
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
*/

char mymap[maxn+1][maxn+1];
int myx,myy;
int qmax=-1,maxx=-1,maxy=-1;
int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};


bool book[maxn+1][maxn+1];

int getsum(int x,int y)
{
	int sum=0;
	int bufx,bufy;
	
	for(int k=0;k<4;k++)
	{
		bufx=x;
		bufy=y;
		while(mymap[bufx][bufy]!='#')
		{
			if(mymap[bufx][bufy]=='G') sum++;
			bufx+=next[k][0];
			bufy+=next[k][1];
		}
	}
	
	return sum;
}

void dfs(int myx,int myy)
{
	int tx,ty;
	
	int sum=getsum(myx,myy);
	if(sum>qmax)
	{
		qmax=sum;
		maxx=myx;
		maxy=myy;
	}
	
	for(int k=0;k<4;k++)
	{
		tx=myx+next[k][0];
		ty=myy+next[k][1];
		if(tx<0 || ty<0 || tx>=maxn || ty>=maxn) continue;
		
		if(mymap[tx][ty]=='.' && !book[tx][ty])
		{
			book[tx][ty]=true;
			dfs(tx,ty);
		}
	}
	
	return;
}

int main()
{
	for(int i=0;i<maxn;i++) memset(book[i],false,sizeof(book[i]));
	cin >> myx >> myy;
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++) cin >> mymap[i][j];
	//initialized
	
	book[myx][myy]=true;
	dfs(myx,myy);
	
	cout << maxx << " " << maxy << " " << qmax << endl;

	return 0;
}

