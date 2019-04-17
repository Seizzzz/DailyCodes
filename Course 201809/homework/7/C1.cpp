#include <stdio.h>

int isprim(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
}

int pr(int n)
{
	if(isprim(n))
	{
		printf("%d",n);
		return 0;
	}
	else
	{
		for(int i=2;i*i<=n;i++)
		{
			
			if(n%i==0)
			{
				printf("%d*",i);
				pr(n/i);
				break;
			}
		}
	}
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
		else pr(i);
		printf("\n");
	}
	
	
	return 0;
}
