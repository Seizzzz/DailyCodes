#include <bits/stdc++.h>
using namespace std;

struct node
{
	int price;
	int quantity;
}peasant[5005];

bool cmp(struct node a,struct node b)
{
	return a.price<b.price;
}

int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=0;i<m;i++)
	{
		cin >> peasant[i].price >> peasant[i].quantity;
	}
	
	sort(peasant,peasant+m,cmp);
	
	int sum=0;
	
	for(int i=0;i<m;i++)
	{
		if(peasant[i].quantity>=n)
		{
			sum+=n*peasant[i].price;
			break;
		}
		else
		{
			n-=peasant[i].quantity;
			sum+=peasant[i].price*peasant[i].quantity;
		}
	}
	
	cout << sum << endl;

	return 0;
}

