#include <bits/stdc++.h>
using namespace std;

struct node
{
	int number;
	int equal;
}num[23];

bool cmp(struct node a,struct node b)
{
	return a.equal>b.equal;
}

int main()
{
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++) cin >> num[i].number;
	
	for(int i=0;i<n;i++)
	{
		num[i].equal=num[i].number;
		while(num[i].equal<10000000) num[i].equal*=10;
	}
	
	sort(num,num+n,cmp);
	
	for(int i=0;i<n;i++) cout << num[i].number;
	cout << endl;

	return 0;
}

