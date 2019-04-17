#include <bits/stdc++.h>
using namespace std;

struct node
{
	int w; //È¨Öµ 
	int d; //ÐòºÅ
}que[20005];

int extra[20005];

int n,k;

bool cmp1(struct node a,struct node b)
{
	if(a.w==b.w) return a.d<b.d;
	return a.w>b.w;
}

int main()
{
	cin >> n >> k;
	
	for(int i=1;i<=10;i++) cin >> extra[i];
	for(int i=1;i<=n;i++)
	{
		cin >> que[i].w;
		que[i].d=i;
	}
	sort(que+1,que+n+1,cmp1);
	
	for(int i=1;i<=n;i++) que[i].w+=extra[((i-1)%10)+1];
	
	sort(que+1,que+n+1,cmp1);
	
	for(int i=1;i<=k;i++) cout << que[i].d << " ";
	cout << endl;
	
	return 0;
}

