#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	qsort(a,n,sizeof(a[0]),cmp);
	
	n=(n%2==0)? n/2:(n+1)/2;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0) sum+=a[i]/2;
		else sum+=(a[i]+1)/2;
	}

	printf("%d\n",sum);
	return 0;
}

