#include <bits/stdc++.h>
using namespace std;

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
	int w = sizeof(int) << 3;
	return (unsigned)signed_high_prod((int)x,(int)y) + ((x >> (w-1)) * y + (y >> (w-1)) * x);
	//补码溢出的部分 + 无符号数最高位作为乘积项的溢出 + (最高位和最高位的溢出(此处无需)) = 无符号数溢出的部分 
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	cout << signed_high_prod(3,3);

	return 0;
}

