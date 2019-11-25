#include <bits/stdc++.h>
using namespace std;

long decode2(long x, long y, long z)
{
	y -= z;
	x *= y;
	y <<= 63;
	y >>= 63;
	y ^= x;
	return y;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	

	return 0;
}

