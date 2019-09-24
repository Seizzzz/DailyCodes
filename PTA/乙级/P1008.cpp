#include <bits/stdc++.h>
using namespace std;

int num[105];

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n,m;
	cin >> n >> m;
	
	for(int i=0;i<n;++i) cin >> num[i];
	
	m = m%n;
	if(m==0)
	{
		cout << num[0];
		for(int i=1;i<n;++i) cout << " " << num[i];
		cout << endl;
		return 0;
	}
	
	int st=n-m,pt=st;
	
	cout << num[pt++];
	if(pt == n) pt=0;
	
	while(pt!=st)
	{
		cout << " " << num[pt];
		if(++pt == n) pt=0;
	}
	
	cout << endl;

	return 0;
}

