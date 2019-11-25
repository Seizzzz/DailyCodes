#include <bits/stdc++.h>
using namespace std;

long switch_prob(long x, long n){
	long result = x;
	switch(n){
		case '2'
		case '0':{
			result = 8 * x;
			break;
		}
		case '3':{
			result = x;
			result >>= 0x3;
			break;
		}
		case '4':{
			result = x;
			result <<= 0x4;
			result -= x;
			x = result;
			x *= x;
			result = x + 0x4b;
			break;
		}
		case '5':{
			x *= x;
			result = x + 0x4b;
			break;
		}
		
		case '1':
		default:{
			result = x + 0x4b;
			break;
		}
	}
	return result;
}


int main()
{
	std::ios::sync_with_stdio(false);
	
	

	return 0;
}

