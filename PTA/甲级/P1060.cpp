#include <bits/stdc++.h>
using namespace std;

struct item
{
	int importance;
	int price;
}mylist[30];

int money,n,maxvalue=0;
bool vis[30];

void dfs(int nowprice,int nowvalue)
{
	if(nowprice>money) return;
	if(nowvalue>maxvalue) maxvalue=nowvalue;
	
	for(int i=0;i<n;i++)
	{
		if(vis[i])
		{
			vis[i]=false;
			dfs(nowprice+mylist[i].price,nowvalue+(mylist[i].price*mylist[i].importance));
			vis[i]=true;
		}
	}
	
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> money >> n;
	for(int i=0;i<n;i++) cin >> mylist[i].price >> mylist[i].importance;
	for(int i=0;i<n;i++) vis[i]=true;
	
	dfs(0,0);
	
	cout << maxvalue << endl;

	return 0;
}

