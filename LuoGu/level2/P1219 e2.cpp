#include <bits/stdc++.h>
#define MAXN 13
using namespace std;

int maxn;
int ans=0;
bool mymap[MAXN][MAXN];

int next[8][2]={{-1,-1},{-1,1},{1,-1},{1,1},{0,-1},{0,1},{-1,0},{1,0}}; //左上 右上 左下 右下 左右上下 

bool check(int i,int j)
{
	for(int direction=0;direction<8;direction++)
	{
		int bufi=i,bufj=j;
		while(bufi<maxn && bufj<maxn && bufi>=0 && bufj>=0)
		{
			if(mymap[bufi][bufj]);
			else return false;
			bufi+=next[direction][0];
			bufj+=next[direction][1];
		}
	}
	return true;
}

void testprnt()
{
	for(int i=0;i<maxn;i++)
	{
		for(int j=0;j<maxn;j++)
		{
			if(!mymap[i][j]) cout << "o";
			else cout << "_";
		}
		cout << endl;
	}
	return;
}

void prnt()
{
	for(int i=0;i<maxn;i++)
	{
		for(int j=0;j<maxn;j++)
		{
			if(!mymap[i][j])
			{
				cout << j << " ";
				break;
			}
		}
	}
	return;
}

void init()
{
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++) mymap[j][i]=true;
	return;
}

void dfs(int i,int j,int chess)
{
	testprnt();
	if(i>=maxn)
	{
		init();
		return;
	}
	if(chess==7)
	{
		prnt();
		init();
		return;
	}
	
	if(check(i,j))
	{
		mymap[i][j]=false;
		if(j==maxn-1) dfs(i+1,0,chess+1);
		else dfs(i,j+1,chess+1);
	}
	else
	{
		if(j==maxn-1) dfs(i+1,0,chess);
		else dfs(i,j+1,chess);
	}
	
	return;
}

int main()
{
	cin >> maxn;
	
	init();
	//initialized
	
	for(int i=0;i<maxn;i++) dfs(0,i,0);

	return 0;
}

