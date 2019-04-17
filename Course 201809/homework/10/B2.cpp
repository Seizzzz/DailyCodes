#include <stdio.h>
int main()
{
	int h,l;
	scanf("%d%d",&h,&l);
	
	int a[h][l],i,j,flag,max,k;
	for (i=0;i<h;i++)
	{
		for (j=0;j<l;j++) scanf("%d",&a[i][j]);
	}
	
	
	for (i=0;i<h;i++)
	{
		max=a[i][0];
		k=0;
		for (j=0;j<l;j++)
		{
			if (a[i][k]<a[i][j])
			{
				max=a[i][j];
				k=j;
			}
		}
		
		flag++;
		
		for (j=0;j<h;j++)
		{
			if (a[i][k]>a[j][k])
			{
				flag=0;
				break;
			}
		}
		
		if (flag)
		{
			printf("The saddle point is (%d,%d)=%d.\n",i,k,max);
			break;
		}
		
	}
	if (flag==0) printf("There is no saddle point in the matrix.\n");
	
	return 0;
}
