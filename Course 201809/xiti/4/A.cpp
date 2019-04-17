#include <stdio.h>

int fun(int x)
{
	if(x<1) return x;
	else if(x>=1 && x<=10) return 2*x-1;
	else if(x>10 && x<=100) return 3*x-11;
	else return x*x-24;
}

int main()
{
	int x;
	scanf("%d",&x);
	printf("The result is:y=%d\n",fun(x));
	
	return 0;
}
