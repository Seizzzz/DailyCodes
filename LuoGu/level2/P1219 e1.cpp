#include <bits/stdc++.h>
#define maxn 6
using namespace std;

bool mymap[maxn][maxn];

int next[4][2]={{1,1},{-1,-1},{1,-1},{-1,1}};
int ans=0;
int cnt[10];

int k=0;

void testprnt()
{
	for(int i=0;i<maxn;i++)
	{
		for(int j=0;j<maxn;j++)
		{
			if(mymap[i][j]) cout << "_";
			else cout << "o";	
		}
		cout << endl;
	}
}

void init()
{
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++) mymap[i][j]=true;
	return;
}

void dfs(int i,int j,int chess)
{
	testprnt();
	
	if(i>maxn || j>maxn || chess>8)
	{
		if(chess==8)
		{
			for(int buf=1;buf<=8;buf++) cout << cnt[buf] << " ";
			cout << endl;
		}
		k++;
		init();
		mymap[0][k]=false;
		dfs(0,k,0);
	}
	
	int bufi=i,bufj=j;
	bool flag=true;
	for(int status=0;status<4;status++)
	{
		bufi=i+next[status][0];
		bufj=j+next[status][1];
		
		while(bufi<maxn && bufj<maxn && bufi>=0 && bufj>=0)
		{
			if(mymap[bufi][bufj]);
			else flag=false;
			
			bufi+=next[status][0];
			bufj+=next[status][1];
		}
		if(!flag) break;
	}
	
	if(flag)
	{
		mymap[i][j]=false;
		chess++;
		cnt[chess]=j;
		if(j<maxn) dfs(i,j+1,chess+1);
		else dfs(i+1,0,chess+1);
	}
	else
	{
		if(j<maxn) dfs(i,j+1,chess);
		else dfs(i+1,0,chess);
	}
	
	return;
}

int main()
{
	init();
	//initialized
	
	mymap[0][k]=false;
	dfs(0,k,0);

	return 0;
}

