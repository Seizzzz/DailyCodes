#include <bits/stdc++.h>
using namespace std;

struct node
{
	char occupation[12];
	bool outward;
}people[100005];

int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> people[i].outward >> people[i].occupation;
	
	bool right;
	int number,now=1;
	while(m--)
	{
		cin >> right >> number;
		if(people[now].outward)
		{
			if(right)
			{
				now-=number;
				while(now<1) now+=n;
			}
			else
			{
				now+=number;
				while(now>n) now-=n;
			}
		}
		else
		{
			if(right)
			{
				now+=number;
				while(now>n) now-=n;
			}
			else
			{
				now-=number;
				while(now<1) now+=n;
			}
		}

	}
	
	cout << people[now].occupation << endl;

	return 0;
}

