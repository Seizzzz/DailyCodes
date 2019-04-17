#include <bits/stdc++.h>
using namespace std;

int need=9;
bool vis[9];
int temp[9];

void dfs(int have)
{
	if(have==need)
	{
		if(temp[0]>=temp[3] && temp[1]>=temp[4] && temp[2]>=temp[5])
		{
			if(temp[0]*100+temp[1]*10+temp[2]+temp[3]*100+temp[4]*10+temp[5]==temp[6]*100+temp[7]*10+temp[8])
			{
				cout << temp[0]<<temp[1]<<temp[2]<<"+"<<temp[3]<<temp[4]<<temp[5]<<"="<<temp[6]<<temp[7]<<temp[8];
				cout << endl;
			}
		}
		return;
	}
	for(int i=0;i<9;i++)
	{
		if(vis[i])
		{
			temp[have]=i;
			vis[i]=false;
			dfs(have+1);
			vis[i]=true;
		}
	}
	return;
}

int main()
{
	memset(vis,true,sizeof(vis));
	memset(temp,0,sizeof(temp));
	
	dfs(0);

	return 0;
}

