#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	char c,a[100];
	int cou=1;
	
	gets(a);
	
	int error=0,j=1;
	for(;a[j]!='.';j++)
	{
		if(j>20)
		{
			error=1;
			break;
		}
	}
	
	int p=1;
	for(;a[p]!='#';p++);
	
	if(error==1)
	{
		double sum=0;
		int count=p-1;
		for(int i=0;i<p;i++)
		{
			sum+=(pow(2,count))*(double)(a[i]-'0');
			count--;
		}
		printf("%d\n",(int)sum);
		return 0;
	}
	
	double sum=0;
	int count=j-1;
	
	for(int i=0;i<j;i++)
	{
		sum+=(pow(2,count))*(double)(a[i]-'0');
		count--;
		//printf("%lf %lf %lf\n",pow(2,count),(double)(a[i]-'0'),sum);
	}
	
	count=-1;
	for(int i=j+1;i<p;i++)
	{
		sum+=(pow(2,count))*(double)(a[i]-'0');
		count--;
		//printf("%lf %lf %lf\n",pow(2,count),(double)(a[i]-'0'),sum);
	}
	//1011.101#
	
	printf("%.6lf\n",sum);
	
	return 0;
}
