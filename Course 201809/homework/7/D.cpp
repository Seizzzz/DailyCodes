#include <stdio.h>
#include <math.h>

int isprim(long long n)
{
	for(long long i=2;i*i<=n;i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
}

long long reverseNum(long long n,int len)
{
	long long sum=0;
	
	long long count=1;
	for(int i=len-1;i>=0;i--)
	{
		sum+=((n/(long long int)pow(10,i))%10)*count;
		count*=10;
	}
	
	return sum;
}

int main()
{
	long long a,b;
	scanf("%lld%lld",&a,&b);
	
	for(long long i=a;i<=b;i++)
	{
		if(i==1) continue;
		if(isprim(i))
		{
			int len=0;
			for(;i/(long long int)pow(10,len)!=0;len++);
			if(i==reverseNum(i,len)) printf("%lld\n",i);
		}
	}
	
	return 0;
}
