#include <stdio.h>
#include <string.h>
/*
8
2
0 1 2 0 1 1 4 5
*/


int main()
{
	int n,flag;
	scanf("%d%d",&n,&flag);
	
	int a[n+5];
	int b[n+5];
	int c[n+5];
	
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));

	if(flag==1)
	{
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		
		for(int i=1;i<n;i++)
		{
			int cnt=0;
			for(int j=0;j<i;j++)
			{
				if(a[j]<a[i]) cnt++;
			}
			b[i]=cnt;
		}
		
		for(int i=0;i<n;i++) printf("%d ",b[i]);
		printf("\n");
	}
	else
	{
		for(int i=0;i<n;i++) scanf("%d",&b[i]);
		
		for(int i=n-1;i>=0;i--)
		{
			int s=0;
			for(int j=0;j<=n-1;j++)
			{
				if(s==b[i] && c[j]==0)
				{
					a[i]=j;
					c[j]++;
					break;
				}
				if(c[j]==0) s++;
			}
		}
		for(int i=0;i<n;i++) printf("%d ",a[i]);
		
		printf("\n");
	}


	return 0;
}
