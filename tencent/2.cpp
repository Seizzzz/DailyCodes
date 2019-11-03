#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<int> a;
	a.resize(n);
	for(int i=0;i<n;++i) cin >> a[i];
	if(n%2) a[n] = 0;
	
	sort(a.begin(),a.end());
	
	int sum=0,i;
	for(i=n-1;i>0;i-=2)
	{
		sum+=(a[i]-a[i-1]);
	}
	if(i==0) sum+= a[0];
	
	cout << sum << endl;

	return 0;
}

