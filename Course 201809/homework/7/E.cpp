#include <stdio.h>
#include <math.h>

int numConvert(long long num,long long m,long long n)
{
	//转为十进制 
	int len=0;
	for(;num/(long long int)pow(10,len)!=0;len++);	
	len--;
	
	long long sum=0;
	for(;len>=0;len--)
	{
		sum+=((num/(long long)pow(10,len))%10)*pow(m,len);
	}
	//printf("%lld\n",sum);
	//转为n进制
	len=0;
	for(;sum/(long long int)pow(10,len)!=0;len++);	
	//printf("%d",len);
	
	long long sum1=0;
	int len0=0;
	while(sum!=0)
	{
		sum1+=(sum%n)*pow(10,len0);
		sum=sum/n;
		len0++;
		//printf("%d",len0);
	}
	//printf("%lld\n",sum1);
	return sum1; 
}
int main()
{
	long long num,m,n;
	scanf("%lld%lld%lld",&num,&m,&n);
	
	printf("%lld\n",numConvert(num,m,n));
	
	return 0;
}
