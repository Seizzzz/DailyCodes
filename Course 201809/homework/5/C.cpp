#include <stdio.h>
#include <math.h>

double hs(double x,int a,int b,int c,int d)
{
	return a*x*x*x+b*x*x+c*x+d;
}

double dhs(double x,int a,int b,int c)
{
	return 3*a*x*x+2*b*x+c;
}

int main()
{
	int a,b,c,d;  //ax^3+bx^2+cx+d=0
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	double x1=1,x2=5;
	
	while(fabs(x1-x2)>1e-5)
	{
		x2=x1-(hs(x1,a,b,c,d)/dhs(x1,a,b,c));
		x1=x2-(hs(x2,a,b,c,d)/dhs(x2,a,b,c));
	}
	
	printf("%lf\n",x1);
	
	return 0;
}
