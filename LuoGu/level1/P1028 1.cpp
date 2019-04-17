#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int a[1005];
	a[0]=a[1]=1;
	
	for(int i=2;i<=n;i++)
	{
		a[i]=a[i-1];
		if(i%2==0) a[i]+=a[i/2];
	}
	
	printf("%d\n",a[n]);

	return 0;
}

