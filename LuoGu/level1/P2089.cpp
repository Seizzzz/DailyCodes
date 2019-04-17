#include <stdio.h>


int n;
int temp[10];
int ans[10005][10];
int anskind=0;

void dfs(int total,int xv)
{
	if(total<=n)
	{
		if(xv==10)
		{
			if(total==n)
			{
				for(int i=0;i<10;i++) ans[anskind][i]=temp[i];
				anskind++;
			}
		}
		else
		{
			for(int i=1;i<=3;i++)
			{
				temp[xv]=i;
				dfs(total+i,xv+1);
			}
		}
	}
}


int main()
{
	scanf("%d",&n);
	dfs(0,0);
	printf("%d\n",anskind);
	
	for(int i=0;i<anskind;i++)
	{
		for(int j=0;j<10;j++) printf("%d ",ans[i][j]);
		printf("\n");
	}
	

	return 0;
}

