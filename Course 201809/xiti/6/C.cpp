#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int a[12],b[12];
	
	
	long long sum=0;
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	for(int i=0;i<n;i++) scanf("%d", &b[i]);
	
	for(int i=0;i<n;i++)
	{
		sum+= a[i]*b[i];
	}
	
	printf("%lld\n",sum);

	return 0;
}

