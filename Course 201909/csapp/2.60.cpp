#include <bits/stdc++.h>
using namespace std;

unsigned replace_type(unsigned x,int i,unsigned char b)
{
	unsigned int re1=0x0,re2=0x0;
	re1 = ~re1; //re1 = 0xFFFFFFFF
	re2 += 0xFF; //re2 = 0x000000FF
	for(int sal = 0;sal < i; ++sal) re2 <<= 8; //re2 = 0x00FF0000
	re1 ^= re2; //re1 = 0xFF00FFFF
	x &= re1; //x = 0xFF00FFFF & 0x12345678 = 0x12005678
	re2 = (unsigned int)b; //0xAB 
	for(int sal = 0;sal < i; ++sal) re2 <<= 8; // re2 = 0x00AB0000
	x |= re2; //x = 0x12005678 | 0x00AB0000 = 0x12AB5678
	return x;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	printf("%x\n",replace_type(0x12,0,0xAB));
	printf("%x\n",replace_type(0x12345678,0,0xAB));

	return 0;
}

