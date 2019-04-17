#include <stdio.h>

int main()
{
	int a,b,c,n;
	scanf("%d",&n);
	
	c=n%10;
	if(c==0)
	{
		printf("The number cannot be changed.");
	}
	else
	{
	a=n/100;
	b=(n%100)/10;
	
	a=a+c;
	c=a-c;
	a=a-c;
	
	printf("%d",100*a+10*b+c);
	}
}
