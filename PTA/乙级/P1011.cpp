#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	for(int i=1;i<=n;++i)
	{
		long long a,b,c;
		cin >> a >> b >> c;
		cout << "Case #" << i << ": ";
		if(a+b>c) cout << "true" << endl;
		else cout << "false" << endl;
	}

	return 0;
}

