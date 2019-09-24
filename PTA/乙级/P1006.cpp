#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	int bw = n/100,sw=(n/10)%10,gw=n%10;
	for(int i=0;i<bw;++i) cout << "B";
	for(int i=0;i<sw;++i) cout << "S";
	for(int i=1;i<=gw;++i) cout << i;
	
	cout << endl;

	return 0;
}

