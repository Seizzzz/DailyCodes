#include <bits/stdc++.h>
using namespace std;

struct node
{
	string word;
	int len;
}wordlist[22];

int vis[22],maxlen=0,n;

int repeat(struct node a,struct node b)
{
	
	return 0;
}

void dfs(struct node previous,int len)
{
	if(len>maxlen) maxlen=len;
	
	for(int i=0;i<n;i++)
	{
		int rep=repeat(previous,wordlist[i]);
		if(rep && vis[i]<=2)
		{
			dfs(wordlist[i],len+wordlist[i].len-rep);
		}
	}
}

int main()
{
	cin >> n;
	
	for(int i=0;i<n;i++)
	{
		cin >> wordlist[i].word;
		wordlist[i].len=wordlist[i].word.length();
		vis[i]=0; //by the way
	}
	
	struct node start;
	cin >> start.word;
	start.len=1;
	
	dfs(start,1);

	return 0;
}

