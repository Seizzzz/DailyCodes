#include <stdio.h>
/*
4
1 1 35.6
1 2 23.1
1 1 89.3
4 5 22.6
*/

int main()
{
	int n;
	scanf("%d",&n);
	
	float num[8][8]={0};
	
	while(n--)
	{
		int a,b;
		double c;
		scanf("%d%d",&a,&b);
		scanf("%lf",&c);
		
		num[b][a]=num[b][a] + c;
	}
	
	//printf("\tsaler1\tsaler2\tsaler3\tsaler4\ttotal\n");
	
	double sum=0;
	
	for(int i=1;i<=5;i++)
	{
		//printf("prod%d\t",i);
		sum=0;
		for(int j=1;j<=4;j++) 
		{
			printf("%.1f\t",num[i][j]);
			sum = sum + num[i][j];
		}
		
		printf("%.1lf\n",sum);
	}
	
	//printf("total\t");
	
	double sumtotal=0;
	for(int j=1;j<=4;j++)
	{
		sum=0;
		for(int i=1;i<=5;i++)
		{
			sum = sum + num[i][j];
		}
		printf("%.1lf\t",sum);
		sumtotal = sumtotal + sum;
	}
	
	printf("%.1lf\n",sumtotal);

	return 0;
}

