#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	long long int a[100];
	a[0]=0;
	a[1]=1;
	a[2]=1;
	
	for(int i=3;i<=n;i++)
	{
		a[i]=a[i-2]+a[i-1];
	}
	
	int count=1;
	for(int i=1;i<=n;i++)
	{
		if(count%5==0) printf("%12lld\n",a[i]);
		else printf("%12lld",a[i]);
		count++;
	}
	
	printf("\n");
	return 0;
}
