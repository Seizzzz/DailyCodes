#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	 
	int** point;
	point=(int**)malloc(sizeof(int*) * n);
	
	for(int i=0;i<n;i++) point[i]=(int*)malloc(sizeof(int) * m);
	
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) scanf("%d",&point[i][j]);
		
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) printf("%d ",&point[i][j]);
		printf("\n");
	}
	
	
	
	for(int i=0;i<n;i++) free(point[i]);
	free(point);
	
	return 0;
}

