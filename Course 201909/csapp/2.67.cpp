#include <bits/stdc++.h>
#include <limits.h> 
using namespace std;

//A.
/*
����ʱ������warning��ԭ��������
һ�������ƵĴ�С�����˸û�����int���ֳ� 
�����Ĳ�����"C���Ա�׼"��Ӧ������δ�����
*/ 
//B.
int bad_int_size_is_32()
{
	int set_msb = 1 << 31;
	int beyond_msb = set_msb << 1;
	return set_msb && !beyond_msb;
}
//C.
int bad_int_size_is_32()
{
	int set_msb = 1 << 15;
	int set_msb1 = set_msb << 15;
	int set_msb2 = set_msb1 << 1;
	int beyond_msb = set_msb2 << 1;
	return set_msb2 && !beyond_msb;
}



int main()
{
	std::ios::sync_with_stdio(false);

	printf("%d",bad_int_size_is_32());

	return 0;
}

