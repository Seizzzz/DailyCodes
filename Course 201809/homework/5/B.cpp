#include <stdio.h>
#include <math.h>

int main()
{
	double a;
	scanf("%lf#",&a);
	printf("%lf\n",a);
	
	int len=0;
	for(;a/(int)pow(10,len)>1;len++);
	printf("%d\n",len);
	int le=0;
	for(;(a/pow(10,len))*(int)pow(10,len)>0;len++);
	printf("%d\n",le);
	
	
	return 0;
}
