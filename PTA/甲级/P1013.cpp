#include <bits/stdc++.h>
using namespace std;

struct node
{
	int a;
	int b;
}info[1000002];
int ancest[1002];
int n,m,k;

int parent(int n)
{
	if(ancest[n] == n) return n;
	else return parent(ancest[n]);
}

void merge(int a,int b)
{
	int pa = parent(a),pb = parent(b);
	if(pa != pb) ancest[a] = pb;
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	cin >> n >> m >> k;
	
	for(int i=0;i<m;++i) cin >> info[i].a >> info[i].b;
	
	while(k--)
	{
		int tosearch;
		cin >> tosearch;
		
		for(int i=1;i<=n;++i) ancest[i] = i;
		for(int i=0;i<m;++i)
		{
			if(info[i].a!=tosearch && info[i].b!=tosearch) merge(info[i].a,info[i].b);
		}
		
		int ans = 0;
		for(int i=1;i<=n;++i)
		{
			if(ancest[i] == i) ++ans;
		}
		cout << ((ans-2<0)? 0:ans-2) << endl;
	}

	return 0;
}

