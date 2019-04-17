#include <stdio.h>
#include <math.h>

int main()
{
	float a,b,c,d;
	scanf("%f%f%f",&a,&b,&c);
	d=pow(b,2)-4*a*c;
	float x1=(-b+sqrt(d))/(2*a), x2=(-b-sqrt(d))/(2*a);
	
	if(a==0)
	{
		printf("The equation is not quadratic.");
	}
	else
	{
		if(fabs(x1-x2)<=1e-6)
		{
			printf("The equation has two equal roots: %.4f.",x1);
		}
		else
		{
			if(d>0)
			{
				printf("The equation has two distinct real roots: %.4f and %.4f.",x1,x2);
			}
			else
			{
				printf("The equation has two complex roots: %.4f+%.4fi and %.4f-%.4fi.",-b/(2*a),sqrt(fabs(d))/(2*a),-b/(2*a),sqrt(fabs(d))/(2*a));
			}
		}
		
		
	}
	return 0;
}
