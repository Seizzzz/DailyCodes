#include <stdio.h>

long long int gys(long long int m,long long int n)
{
	long long int m1=m,n1=n,t;
	while(m1%n1)
	{
		t=m1%n1;
		m1=n1;
		n1=t;
	}
	return n1;
}

int main()
{
	long long int m,n;
	scanf("%lld%lld",&m,&n);
	if(m<n)
	{
		long long int trans=m;
		m=n; n=trans;
	}
	long long int g=gys(m,n);
	printf("%lld\n",g);
	
	return 0;
}


