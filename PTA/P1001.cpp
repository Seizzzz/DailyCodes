#include <stdio.h>

int main()
{
	long long n,count=0;
	scanf("%lld",&n);
	while(n!=1)
	{
		if(n%2) n=(3*n+1)/2;
		else n=n/2;
		count++;
	}
	printf("%lld\n",count);
	return 0;
}
