#include <stdio.h>
#include <math.h>

int n;

double cal(double number,int m)
{
	if(m==n+1) return number;

	return cal(sqrt(number+m),m+1);
}

int main()
{
	double x;
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lf",&n,&x);
		printf("%.3lf\n",cal(x,1));
	}
	

	return 0;
}

