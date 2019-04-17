#include <stdio.h>
#include <math.h>

int reverseNum(int n,int len)
{
	int sum=0;
	
	int count=1;
	for(int i=len-1;i>=0;i--)
	{
		sum+=((n/(long long int)pow(10,i))%10)*count;
		count*=10;
	}
	
	return sum;
}

int main()
{
	long long int n;
	scanf("%lld",&n);
	
	int len=0;
	for(;n/(long long int)pow(10,len)!=0;len++);
	
	
	printf("The reverse form of number %lld is %lld.\n",n,reverseNum(n,len));
	
	
	return 0;
}
