#include <stdio.h>
#include <math.h>

int main()
{
	long long n,len=0;
	scanf("%lld",&n);
	
	for(;n/(long long int)pow(10,len)!=0;len++);
	
	if(len!=1) printf("The integer %lld has %lld digits.\n",n,len);
	else printf("The integer %lld has %lld digit.\n",n,len);
	
	
	return 0;
}
