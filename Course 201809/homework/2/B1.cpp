#include <stdio.h>

int main()
{
	char a,b,c;
	scanf("%c%c%c",&a,&b,&c);
	int a1=a,b1=b,c1=c;
	//printf("%d%d%d",a1,b1,c1);
	
	if((b1>=65&&b1<=90)||(b1>=97&&b1<=122))
	{
		if((a1>=65&&a1<=90)||(a1>=97&&a1<=122))
		{
			if((c1>=65&&c1<=90)||(c1>=97&&c1<=122))
			{
				if((b1-1==a1 || b1+1==a1)&&(b1-1==c1 || b1+1==c1)) 
				{
					printf("Yes");
				}
				else
				{
					printf("No");
				}
			}
			else
			{
				printf("No");
			}
		}
		else
		{
			printf("No");
		}
	}
	else
	{
		printf("No");
	}
	
	
	
	
	
	return 0;
}
