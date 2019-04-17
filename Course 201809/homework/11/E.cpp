#include <stdio.h>

int main()
{
	int n,x=0,y=1;
	scanf("%d",&n);
	
	int a[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) a[i][j]=0;
	a[0][0]=1;
	
	int num=2;

	while(x!=n && y!=n)
	{
		a[x][y]=num;
		if(x==0 || y==0 || x=)
		{
			if(x==0 && a[x][y]==a[x][y-1]+1)
			{
				x=x+1;
				y=y-1;
			}
			else if(x==0 && a[x][y]==a[x+1][y-1]+1)
			{
				y=y+1;
			}
			else if(y==0 && a[x][y]==a[x-1][y+1]+1)
			{
				x=x+1;
			}
			else if(y==0 && a[x][y]==a[x-1][y]+1)
			{
				x=x-1;
				y=y+1;
			}
			else
		}
		else
		{
			if(a[x][y]==a[x+1][y-1]+1)
			{
				x=x-1;
				y=y+1;
			}
			else if(a[x][y]==a[x-1][y+1]+1)
			{
				x=x+1;
				y=y-1;
			}
		}
		num++;	
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) printf("%d ",a[j][i]);
		printf("\n");
	}

	return 0;
}

