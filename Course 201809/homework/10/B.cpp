#include <stdio.h>

/*
4 5
1 2 3 4 5
2 4 6 8 10
3 6 9 12 15
4 8 12 16 20
*/

int main()
{
	int h,l;
	scanf("%d%d",&h,&l);
	
	int a[h+2][l+2];
	
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=l;j++) scanf("%d",&a[i][j]);
	}
	
	//int flag=0;
	
	for(int judh=1;judh<=h;judh++)
	{
		int maxl=1;
		for(int judl=1;judl<=l;judl++)
		{
			if(a[judh][judl] > a[judh][maxl]) maxl=judl;
		}
		//printf("%d ",maxl);
		
		for(int judhh=1;judhh<=h;judhh++)
		{
			if(a[judhh][maxl] < a[judh][maxl]) break;
			
			
			if(judhh==h)
			{
				printf("The saddle point is (%d,%d)=%d.\n",judh-1,maxl-1,a[judh][maxl]);
				return 0;
				//printf("%d %d\n",judh,maxl);
				/*
				flag=1;
				flagh=judh;
				flagl=maxl;
				goto ans;
				*/
			}
		}
	}
	
	printf("There is no saddle point in the matrix.\n");
	return 0;
}

