#include <bits/stdc++.h>
using namespace std;

int mul3div4(int x)
{
	return ((x << 1) + x) >> 2;
}
//((x & (0x1 << 31)) && ((x = (x + (0x1 << 2) - 1) >> 2) || 1)) || (x = x >> 2);

int main()
{
	std::ios::sync_with_stdio(false);
	
	cout << mul3div4(0);

	return 0;
}

