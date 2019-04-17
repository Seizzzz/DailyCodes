#include <stdio.h>

long long cal(long long a,long long b)
{
	if(b==0) return 1;
	
	long long sum=1;
	
	for(long long i=a;i<=b;i++)
	{
		sum*=i;
	}
	return sum;
}

int main()
{
	long long n;
	scanf("%lld",&n);
	
	printf("%lld\n",cal(n+2,2*n+1)/cal(1,n));
	
	
	return 0;
}
