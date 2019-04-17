#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	//上三角 
	for(int j=n;j>0;j--)
	{
		for(int i=j-1;i>0;i--)
		{
			if(i==0)
			{
				break;
			}
			else
			printf(" ");
		}
		if(j<n)
		printf("*");
		else printf("*\n");
		
		
		if(j!=n)
		{	
			for(int j1=n-j;j1>0;j1--)
			{
				if(j1==1)
				{
					printf(" ");
				}
				else
				{
					printf("  ");
				}
				
			}
			if(j<n)
			{
				printf("*\n");
			}
			
		}	
	}
	//下三角 
	n=n-1;
	for(int j=1;j<n+1;j++)
	{
		for(int i=j-1;i>0;i--)
		{
			if(i==0)
			{
				break;
			}
			else
			printf(" ");
		}
		if(j<n)
		printf(" *");
		else printf(" *\n");
		
		
		if(j!=n)
		{	
			for(int j1=n-j;j1>0;j1--)
			{
				if(j1==1)
				{
					printf(" ");
				}
				else
				{
					printf("  ");
				}
				
			}
			if(j<n)
			{
				printf("*\n");
			}
			
		}	
	}
	
	
	
	
}
