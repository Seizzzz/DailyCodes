#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=n-i;j>0;j--) printf(" ");
		for(int k=2*i-1;k>0;k--)
		{
			if(k==1) printf("*\n");
			else printf("*");
		}
	}
	
	for(int i=n-1;i>0;i--)
	{
		for(int j=n-i;j>0;j--) printf(" ");
		for(int k=2*i-1;k>0;k--)
		{
			if(k==1) printf("*\n");
			else printf("*");
		}
	}
	
	return 0;
}
