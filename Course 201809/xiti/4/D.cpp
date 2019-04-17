#include <stdio.h>

int isprim(long long n)
{
	for(long long i=2;i*i<=n;i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
}

int main()
{
	int t;
	long long n;
	scanf("%d",&t);
	
	for(;t>0;t--)
	{
		scanf("%lld",&n);
		for(long long i=2;i<=n/2;i++)
		{
			if(isprim(i))
			{
				for(long long j=2;j<=n/2;j++)
				{
					if(i*j==n)
					{
						if(isprim(j))
						{
							printf("Yes\n");
							goto a;
						}
					}
				}
			}
			
		}
		printf("No\n");
		a:{}
	}
	
	
	return 0;
}
