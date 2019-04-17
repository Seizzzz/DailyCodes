#include <stdio.h>

int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	
	int light[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++) scanf("%d",&light[i][j]);
	}
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x-2>=0 && y-2>=0)
		{
			light[x-2][y-2]= (light[x-2][y-2]==0)? 1:0;
			light[x-2][y]= (light[x-2][y]==0)? 1:0;
			light[x][y-2]= (light[x][y-2]==0)? 1:0;
		}
		if(x-1>=0 && y-1>=0)
		{
			light[x-1][y-1]= (light[x-1][y-1]==0)? 1:0;
			
		}
		light[x][y]= (light[x][y]==0)? 1:0;
		
		
	}
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++) printf("%d ",light[i][j]);
		printf("\n");
	}

	return 0;
}

