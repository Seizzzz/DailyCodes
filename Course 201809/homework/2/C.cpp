#include <stdio.h>

int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	int x1=x;
	if(y==0)
	{
		printf("1");
	}
	else
	{
	for(;y>1;y--)
	{
		x=x*x1;
	}
	printf("%d",x);	
	}
}
