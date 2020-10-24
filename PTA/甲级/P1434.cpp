#include <bits/stdc++.h>
using namespace std;

int r,c;
int ski[102][102];
int sv[102][102];

inline int dfs(int i,int j)
{
	if(sv[i][j]!=1) return sv[i][j];
	
	int now=0;
	if(i>=1 && j>=1 && i<=r && j<=c) //at least
	{
		if(i<r && ski[i][j]>ski[i+1][j]) now=max(now,dfs(i+1,j)+1); //向下滑？ 
		if(j>1 && ski[i][j]>ski[i][j-1]) now=max(now,dfs(i,j-1)+1); //向左滑？ 
		if(j<c && ski[i][j]>ski[i][j+1]) now=max(now,dfs(i,j+1)+1); //向右滑？ 
		if(i>1 && ski[i][j]>ski[i-1][j]) now=max(now,dfs(i-1,j)+1); //向上滑？ 
		sv[i][j]=max(now,sv[i][j]); //mem
	}
	else sv[i][j]=1;
	
	return sv[i][j];
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> r >> c;
	
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
		{
			cin >> ski[i][j];
			sv[i][j]=1; //init
		}
	
	int ans=0;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++) ans=max(ans,dfs(i,j));

	cout << ans << endl;

	return 0;
}

