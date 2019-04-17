#include <stdio.h>
#include <math.h>

int main()
{
	int a,b,c,t;
	double S,Area;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b) {t=a; a=b; b=t;}
	if(a>c) {t=a; a=c; c=t;}
	if(b>c) {t=b; b=c; c=t;}
	
	if(a+b<=c || c-b>=a)
	{
		printf("The egdes cannot make up of a triangle.");
	}
	else
	{
		S=(double)(a+b+c)/2;
		Area=sqrt((S*(S-a)*(S-b)*(S-c)));
		printf("%.3lf",Area);
	}
}
