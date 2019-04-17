#include <stdio.h>
#include <math.h>

int judgeprim(int n)
{
	int k=sqrt(n)+0.5;
	for(int i=2;i<=k;i++) if(n%i==0) return 0;
	if(n<=1) return 0;
	return 1;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	//printf("%d",judgeprim(2003));
	for(int i=2;i<n;i++)
	{
		if(judgeprim(i)==0) continue;
		for(int j=2;j<n;j++)
		{
			int k=n-i-j;
			if(judgeprim(k))
			{
				if(judgeprim(j))
				{
					printf("%d %d %d\n",i,j,k);
					return 0;
				}
			}
		}
	}
}

