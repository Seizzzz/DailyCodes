#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int* a=(int *)malloc(sizeof(int) * n);
	
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	for(int i=0;i<n;i++) printf("%d ",a[i] * (-10));
	printf("\n");

	return 0;
}

