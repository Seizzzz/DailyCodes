#include <bits/stdc++.h>
using namespace std;

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
	int w = sizeof(int) << 3;
	return (unsigned)signed_high_prod((int)x,(int)y) + ((x >> (w-1)) * y + (y >> (w-1)) * x);
	//��������Ĳ��� + �޷��������λ��Ϊ�˻������� + (���λ�����λ�����(�˴�����)) = �޷���������Ĳ��� 
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	cout << signed_high_prod(3,3);

	return 0;
}

