#include <bits/stdc++.h>
using namespace std;

bool vis[100005],yes[100005];

inline bool isprime(int n)
{
	int lim=sqrt(n);
	vis[n]=true;
	for(int i=2;i<=lim;++i)
	{
		if(n%i==0)
		{
			yes[n]=false;
			return false;
		}
	}
	yes[n]=true;
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n,ans=0;
	cin >> n;
	n=n-2;
	
	for(int i=2;i<=n;++i)
	{
		if(vis[i])
		{
			if(yes[i] && isprime(i+2)) ++ans;
		}
		else
		{
			if(isprime(i) && isprime(i+2)) ++ans;
		}
	}
	
	cout << ans << endl;

	return 0;
}

