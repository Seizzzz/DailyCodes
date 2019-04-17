#include <stdio.h>
#include <math.h>

int cnt=1,n;

double cal(double num)
{
	if(cnt<n)
	{
		double num1=sqrt(num+(cnt++));
		cal(num1);
	}
	else return num;
	
}

int main()
{
	int t;
	double x;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&x);
		cnt=1;
		printf("%d",cal(x));
	}
	

	return 0;
}

