#include <bits/stdc++.h>
using namespace std;

struct node
{
	int number;
	int score;
};

bool cmp(node a,node b)
{
	if(a.score==b.score) return a.number<b.number;
	return a.score>b.score;
} 

int main()
{
	int n,m;
	cin >> n >> m;
	
	node info[5005],anslist[5005];
	
	for(int i=0;i<n;i++)
	{
		cin >> info[i].number >> info[i].score;
	}
	
	sort(info,info+n,cmp);
	int k=1.5*m;
	
	int secondscore=info[k-1].score;
	int quantity=0,ans=0;
	for(int i=0;i<n;i++)
	{
		if(info[i].score>=secondscore)
		{
			quantity++;
			anslist[ans]=info[i];
			ans++;
		}
	}
	
	cout << secondscore << " " << quantity << endl;
	for(int i=0;i<ans;i++) cout << anslist[i].number << " " << anslist[i].score << endl;
	
	
	return 0;
}

