#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int num[n][n];
	memset(num,0,sizeof(num));
	
	int end=n*n;
	
	int x=-1,y=0,a=0;
	
	while(a<end)
	{
		while(x+1<n && !num[x+1][y]) num[++x][y]= ++a;
		while(y-1>=0 && !num[x][y-1]) num[x][--y]= ++a;
		while(x-1>=0 && !num[x-1][y]) num[--x][y]= ++a;
		while(y+1<n && !num[x][y+1]) num[x][++y]= ++a;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) printf("%d ",num[j][i]);
		printf("\n");
	}

	return 0;
}

