#include <bits/stdc++.h>
using namespace std;

long loop(long x, int n)
{
	long result = 0;
	long mask;
	for(mask = 1;mask!=0;mask << (n<<56>>56)) {
		result |= (x & mask);
	}
	return result;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	

	return 0;
}

