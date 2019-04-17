#include <stdio.h>

int main()
{
	int n,a3=0,a5=0,a7=0,sum=0;
	while(scanf("%d",&n) && n!=0)
	{
		if(n%3==0) a3++;
		if(n%5==0) a5++;
		if(n%7==0) a7++;
		sum++;
	}
	printf("%.1f%%\n%.1f%%\n%.1f%%",100.0*a3/sum,100.0*a5/sum,100.0*a7/sum);
	
	
	return 0;
}
