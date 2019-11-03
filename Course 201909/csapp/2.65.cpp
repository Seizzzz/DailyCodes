#include <bits/stdc++.h>
using namespace std;

int odd_ones_old(unsigned x)
{
	int ans = 0;
	unsigned int re = 0x1;
	while(re <= x)
	{
		if((re | x) == x) ans = !ans;
		re <<= 1; //re = 0x...001, 0x...010, 0x...100
	}
	return ans;
}

int odd_ones(unsigned x)
{
	x ^= (x>>16); 	//结果存储在0~15位 
	x ^= (x>>8);  	//结果存储在0~7位 
	x ^= (x>>4);  	//结果存储在0~3位 
	x ^= (x>>2);  	//结果存储在0~1位 
	x ^= (x>>1);  	//结果存储在第0位 
	x &= 0x1; 		//清除其它位的值 
	return x;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	for(int i=1;i<20;++i)
	{
		cout << odd_ones_old(i) << " " << odd_ones(i) << endl;
	}

	return 0;
}

