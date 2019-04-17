#include <stdio.h>

/*
3 4
22 45 56 30
19 33 45 38
20 22 66 40
*/

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n][m];
	int b[m];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	for(int i=0;i<m;i++)
	{
		int temp=a[0][i];
		for(int j=0;j<n;j++)
		{
			if(a[j][i]<temp) temp=a[j][i];
		}
		b[i]=temp;
	}
	
	for(int i=0;i<m;i++) printf("%d ",b[i]);
	printf("\n");

	return 0;
}

