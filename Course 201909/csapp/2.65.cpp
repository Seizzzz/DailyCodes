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
	x ^= (x>>16); 	//����洢��0~15λ 
	x ^= (x>>8);  	//����洢��0~7λ 
	x ^= (x>>4);  	//����洢��0~3λ 
	x ^= (x>>2);  	//����洢��0~1λ 
	x ^= (x>>1);  	//����洢�ڵ�0λ 
	x &= 0x1; 		//�������λ��ֵ 
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

