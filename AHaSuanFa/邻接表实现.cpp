#include <bits/stdc++.h>
#define maxn 30
using namespace std;

/*
5
1 4 9
4 3 8
1 2 5
2 4 6
1 3 7
*/

int main()
{
	int u[maxn],v[maxn],w[maxn],first[maxn],next[maxn];
	memset(first,-1,sizeof(first));
	memset(next,-1,sizeof(next));
	//initialized
	
	int kase;
	cin >> kase;
	
	for(int i=1;i<=kase;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		
		if(first[u[i]]!=-1) next[i]=first[u[i]];
		first[u[i]]=i;
		/*
		if(first[u[i]]==-1)
		{
			first[u[i]]=i;
		}
		else
		{
			next[i]=first[u[i]];
			first[u[i]]=i;
		}
		*/
	}

	return 0;
}

