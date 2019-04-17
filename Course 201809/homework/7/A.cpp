#include <stdio.h>
#include <math.h>

int main()
{
	long long n;
	scanf("%lld",&n);
	
	int len=0;
	for(;n/(long long int)pow(10,len)!=0;len++);
	
	len--;
	
	long long sum=0;
	for(;len>=0;len--)
	{
		sum+=((n/(int)pow(10,len))%10)*pow(2,len);
	}
	printf("%lld\n",sum);
	
	return 0;
}
