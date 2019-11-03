#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	long long n,m;
	cin >> n >> m;
	
	cout << (1<<(n-1))*m/((1<<n)-1) << endl;

	return 0;
}

