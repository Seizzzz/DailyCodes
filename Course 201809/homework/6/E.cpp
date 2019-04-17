#include <stdio.h>
int isPerfect(int n)
{
	int sum=0;
	for(int i=1;i<n;i++)
	{
		if(n%i==0) sum+=i;
	}
	
	if(sum==n) return 1;
	else return 0;
}

void printPerfect(int n)
{
	printf("%d=1",n);
	for(int i=2;i<n;i++)
	{
		if(n%i==0) printf("+%d",i);
	}
	printf("\n");
}


int main()
{
	int a,b,count=0;
	scanf("%d%d",&a,&b);

	for(int i=a;i<=b;i++)
	{
		if(isPerfect(i))
		{
			count++;
			printPerfect(i);
		}
	}
	printf("The total number is %d.\n",count);
	return 0;
}
