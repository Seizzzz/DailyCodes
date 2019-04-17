#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
3
5 5 5
3 3 3
1 1 1
*/
int cmp(const void *a,const void *b)
{
	return *(int*)a - *(int*)b;
}


int main()
{
	int n;
	scanf("%d",&n);
	int a[n+2][n+2];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
	}
	
	int sum[n+2];
	memset(sum,0,sizeof(sum));
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) sum[i] = sum[i] + a[i][j];
	}
	
	int sum1[n+2];
	for(int i=0;i<n;i++) sum1[i]=sum[i];
	
	qsort(sum1,n,sizeof(sum1[0]),cmp);
	
	int v[n+2];
	memset(v,0,sizeof(v));
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(sum[j]==sum1[i] && v[j]==0)
			{
				for(int pr=0;pr<n;pr++)
				{
					if(pr==n-1) printf("%d\n",a[j][pr]);
					else printf("%d ",a[j][pr]);
				}
				v[j]++;
				break;
			}
		}
	}

	return 0;
}

