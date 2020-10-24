#include <bits/stdc++.h>
using namespace std;

struct node
{
	int number;
	int strength;
	int score;
}man[100005];

int n,r,q;
int n2;

void compete()
{
	for(int i=1;i<n2;i+=2)
	{
		if(man[i].strength>man[i+1].strength) man[i].score++;
		else man[i+1].score++;
	}
	return;
}

bool cmp(struct node a,struct node b)
{
	if(a.score==b.score) return a.number<b.number;
	return a.score>b.score;
}

int main()
{
	cin >> n >> r >> q;
	n2=2*n;
	
	for(int i=1;i<=n2;i++)
	{
		man[i].number=i;
		cin >> man[i].score;
	}
	for(int i=1;i<=n2;i++) cin >> man[i].strength;
	
	while(r--)
	{
		compete();
		sort(man+1,man+n2+1,cmp);
	}
	
	cout << man[q].number << endl;

	return 0;
}

