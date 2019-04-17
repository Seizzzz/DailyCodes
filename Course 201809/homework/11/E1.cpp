#include <stdio.h>
int main()
{
	int n,a[100][100]={1},x=0,y=0,con=1;
	scanf("%d",&n);
	
	while(x!=n-1 || y!=n-1)
	{
		if(con==1)
		{
			a[x+1][y]=a[x][y]+1;
			x++;
			if(y==0)
			  con=2;
			else if(y==n-1)
			  con=4;
		}
		else if(con==2)
		{
			a[x-1][y+1]=a[x][y]+1;
			x--,y++;
			if(x==0&&y!=n-1)
			  con=3;
			else if(y==n-1)
			  con=1;
			else
			  con=2;
		}
		else if(con==3)
		{
			a[x][y+1]=a[x][y]+1;
			y++;
			if(x==0)
			  con=4;
			else if(x==n-1)
			  con=2;
		}
		else if(con==4)
		{
			a[x+1][y-1]=a[x][y]+1;
			x++,y--;
			if(y==0&&x!=n-1)
			  con=1;
			else if(x==n-1)
			  con=3;
			else
			  con=4; 
		}
	}
	for(x=0;x<n;x++)
	{
		for(y=0;y<n;y++)
		  printf("%d ",a[x][y]);
		printf("\n");
	} 
	return 0;
}

