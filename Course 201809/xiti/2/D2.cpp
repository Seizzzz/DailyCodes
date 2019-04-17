#include <stdio.h>
#include <math.h>

int main()
{
	long long n;
	scanf("%lld",&n);
	
	int len=0;
	while(n/(int)(pow(10,len))!=0)
	{
		len++;
	}
	
	len--;
	int test=0;
	while(len>=0)
	{
		if((len+1)%3==0 && test) printf(",%d",(n/(int)(pow(10,len)))%10);
		else printf("%d",(n/(int)(pow(10,len)))%10);
		len--;
		test++;
	}
	
	
	return 0;
}
