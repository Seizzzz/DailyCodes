#include <bits/stdc++.h>
using namespace std;

int lower_one_mask(int n)
{
	/*(n=32)
	int mask = 0x1;
	mask <<= (n-1); //0x(1000)000
	--mask; //0x(0111)FFF
	mask <<= 1; //0xFFF(1110)
	++mask; //0xFFFF
	*/
	return (((0x1 << (n-1)) - 1) << 1) + 1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	cout << lower_one_mask(1) << endl;
	cout << lower_one_mask(31) << endl;
	cout << lower_one_mask(32) << endl;

	return 0;
}

