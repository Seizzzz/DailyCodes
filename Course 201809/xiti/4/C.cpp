#include <stdio.h>
#include <math.h>

int main()
{
	int h,m,h1,m1;
	long long t;
	scanf("%lld",&t);
	for(;t>0;t--)
	{
		int sum,sum1;
		scanf("%d:%2d",&h,&m);
		scanf("%d:%2d",&h1,&m1);
		
		sum=100*h+m;
		sum1=100*h1+m1;
		
		if(sum1<sum)
		{
			h1+=24;
			printf("%d\n",(h1-h)*60+m1-m);
		}
		else printf("%d\n",(int)fabs((h-h1)*60)+(int)(m1-m));
	}
	
	
	
	
	return 0;
}
