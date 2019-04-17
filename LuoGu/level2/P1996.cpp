#include <bits/stdc++.h>
using namespace std;

struct node
{
	int previous;
	int who;
	int next;
}que[105];

int n,m;

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	
	if(n==0) exit(0);
	
	for(int i=1;i<=n;i++)
	{
		que[i].previous=i-1;
		que[i].who=i;
		que[i].next=i+1;
	}
	que[1].previous=n;
	que[n].next=1;
	
	int i=1,now=1;
	while(que[i].next!=i)
	{
		if(now==m)
		{
			cout << i << " ";
			que[que[i].previous].next=que[i].next;
			que[que[i].next].previous=que[i].previous;
			i=que[i].next;
			now=1;
		}
		else
		{
			now++;
			i=que[i].next;
		}
	}
	
	cout << i << endl;

	return 0;
}

