#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	long long n,m;
	cin >> n >> m;
	int round = n/(m << 1);
	cout << m*m*round << endl;

	return 0;
}

