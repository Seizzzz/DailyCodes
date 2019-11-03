#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	int x;
	scanf("%d",&x);
	
	int A = x + (x << 4),
		B = x - (x << 3),
		C = (x << 6) - (x << 2),
		D = (x << 4) - (x << 7);
	printf("%d %d %d %d",A,B,C,D);

	return 0;
}

