#include <stdio.h>

int isprim(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
}

int print(int n)
{
	//printf("*%d*",n);
	if(n!=1)
	{
		for(int i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				printf("*%d",i);
				n=n/i;
				print(n);
			}
		}
		
	}
	else return 0;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	for(int i=a;i<=b;i++)
	{
		printf("%d=",i);
		if(isprim(i))
		{
			printf("%d\n",i);
			continue;
		}
		else print(i); 
		printf("\n");
	}
}
