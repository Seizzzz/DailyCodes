#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	long long a[n];
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	
	qsort(a,n,sizeof(a[0]),cmp);
	
	for(int i=0;i<n;i++)
	{
		i=n-1? printf("%lld",a[i]):printf("%lld",a[i]);
	}
	
	printf("\n");

	return 0;
}

