#include <bits/stdc++.h>
using namespace std;

int quick(int a,int b,int c)
{
	int ans=1;   //记录结果
	a=a%c;   //预处理，使得a处于c的数据范围之下
	while(b!=0)
	{
		if(b&1) ans=(ans*a)%c;   //如果b的二进制位不是0，那么我们的结果是要参与运算的
		b>>=1;    //二进制的移位操作，相当于每次除以2，用二进制看，就是我们不断的遍历b的二进制位
		a=(a*a)%c;   //不断的加倍
	}
	return ans;
}

int main()
{
	cin >> a >> b >> c;
	cout << quick(a,b,c) << endl;

	return 0;
}

