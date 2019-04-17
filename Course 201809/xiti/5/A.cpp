#include <stdio.h>
#include <math.h>

long long countbinary(long long n)
{
	int len=0;
	//printf("%d ",n);
	while(n/(long long)pow(10,len)!=0)
	{
		len++;
	}
	
	return len;
}

int main()
{
	long long n;
	scanf("%lld",&n);
	
	long long a[100],i=0,c=0;
	while(n!=0)
	{
		i=n%2;
		a[c]=i;
		c++;
		n=n/2;
	}
	c--;
	long long sum=0;
	for(;c>=0;c--)
	{
		sum+=(long long)pow(10,c) *a[c];
	}
	//printf("%lld\n",sum);
	printf("%lld\n",countbinary(sum));
	

	return 0;
}

