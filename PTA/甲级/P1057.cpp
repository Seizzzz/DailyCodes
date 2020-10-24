#include <bits/stdc++.h>
using namespace std;

struct node
{
	int now;
	int times;
}que[100005];

int n,m,ans=0;

int main()
{
	cin >> n >> m;
	//不妨从1开始
	que[0].now=1;
	que[0].times=0;
	
	int head=0,tail=1; // bfs
	
	while(head<tail)
	{
		if(que[head].times==m)
		{
			if(que[head].now==1) ans++;
			head++;
			continue;
		}
		que[tail].now=(que[head].now+1>n)? 1:que[head].now+1;
		que[tail].times=que[head].times+1;
		tail++;
		que[tail].now=(que[head].now-1<1)? n:que[head].now-1;
		que[tail].times=que[head].times+1;
		tail++;
		head++;
		
	} 
	
	cout << ans << endl;

	return 0;
}

