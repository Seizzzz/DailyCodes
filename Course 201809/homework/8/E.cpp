#include <stdio.h>

int main()
{
	int sum;
	scanf("%d",&sum);
	
	if(sum/100>0)
	{
		printf("100:%d\n",sum/100);
		sum=sum%100;
	}
	if(sum/50>0)
	{
		printf("50:%d\n",sum/50);
		sum=sum%50;
	}
	if(sum/20>0)
	{
		printf("20:%d\n",sum/20);
		sum=sum%20;
	}
	if(sum/10>0)
	{
		printf("10:%d\n",sum/10);
		sum=sum%10;
	}
	if(sum/5>0)
	{
		printf("5:%d\n",sum/5);
		sum=sum%5;
	}
	if(sum/2>0)
	{
		printf("2:%d\n",sum/2);
		sum=sum%2;
	}
	if(sum==1)
	{
		printf("1:1\n");
	}

	return 0;
}

