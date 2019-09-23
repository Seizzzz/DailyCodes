#include <bits/stdc++.h>
using namespace std;

int n,m,c1,c2; 
int mymap[502][502];
int val[502];

bool vis[502];
int maxhave=0,cnt=0,minlen=0x7fffffff;

void dfs(int nowat, int have, int len)
{
	if(nowat == c2)
	{
		if(len < minlen)
		{
			cnt=1;
			maxhave = have;
			minlen = len;
		}
		else if(len == minlen)
		{
			cnt++;
			maxhave = max(maxhave,have);
		}
		return;
	}
	
	for(int i=0;i<n;i++)
	{
		if(!vis[i] && mymap[nowat][i]!=0x7fffffff)
		{
			vis[i]=true;
			dfs(i,have+val[i],len+mymap[nowat][i]);
			vis[i]=false;
		}
	}
	
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m >> c1 >> c2;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) mymap[i][j] = 0x7fffffff;
	
	for(int i=0;i<n;i++)
	{
		cin >> val[i];
		vis[i] = false;
	}
	
	for(int i=0;i<m;i++)
	{
		int t1,t2,l;
		cin >> t1 >> t2 >> l;
		mymap[t1][t2]=l;
		mymap[t2][t1]=l;
	}
	
	vis[c1]=true;
	dfs(c1,val[c1],0);
	
	cout << cnt << " " << maxhave << endl;

	return 0;
}

