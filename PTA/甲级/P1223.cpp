#include <bits/stdc++.h>
using namespace std;

struct node
{
	int number;
	int time;
}que[1005];

bool cmp(node a,node b)
{
	return a.time<b.time;
}

int main()
{
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++)
	{
		cin >> que[i].time;
		que[i].number=i;
	}
	
	sort(que+1,que+n+1,cmp);
	
	for(int i=1;i<=n;i++)
	{
		cout << que[i].number << " ";
	}
	cout << endl;
	
	long long total=0,now=0;
	for(int i=1;i<=n;i++)
	{
		total+=now;
		now+=que[i].time;
	}
	
	cout << fixed << setprecision(2) << (double)total/n << endl;
	
	return 0;
}

