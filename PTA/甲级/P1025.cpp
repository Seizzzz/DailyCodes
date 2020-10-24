#include <bits/stdc++.h>
using namespace std;

int n,k,ans=0;

void dfs(int number,int have,int maxdv)
{
	if(have==k)
	{
		if(number==0) ans++;
		return;
	}
	
	for(int divide=maxdv;divide<=number;divide++) dfs(number-divide,have+1,divide);
	return;
}

int main()
{
	cin >> n >> k;
	dfs(n,0,1);
	
	cout << ans << endl;

	return 0;
}

