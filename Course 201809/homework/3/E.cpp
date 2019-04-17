#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=n;i>0;i--)
	{
		for(int j=i;j>0;j--)
		{
			if(j>i/2)
			{
				for(int m=j;m>0;m--)
				{
					if(m=1)
					printf("*");
					else
					{
						printf(" ");
					}
				}
			
			}
		}
	}
}
