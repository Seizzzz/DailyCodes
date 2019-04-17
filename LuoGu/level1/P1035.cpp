#include <stdio.h>

int main()
{
	double K,n=1,sum=0;
	scanf("%lf",&K);
	while(sum<=K)
	{
		sum+=1/n;
		n++;
	}
	printf("%d\n",(int)n-1);
	
	return 0;
}
