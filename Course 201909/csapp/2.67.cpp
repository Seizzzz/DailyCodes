#include <bits/stdc++.h>
#include <limits.h> 
using namespace std;

//A.
/*
编译时编译器warning的原因是由于
一次性左移的大小超过了该机器上int的字长 
这样的操作在"C语言标准"中应该是是未定义的
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

