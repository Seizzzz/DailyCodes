#include <stdio.h>

int main()
{
	int a[5];
	for(int i=0;i<5;i++) scanf("%d",&a[i]);
	
	printf("METHOD 1\n");
	for(int i=4;i>=0;i--) printf("%d ",a[i]);
	printf("\n");
	
	printf("METHOD 2\n");
	for(int i=4;i>=0;i--) printf("%d ",*(a+i));
	printf("\n");
	
	printf("METHOD 3\n");
	for(int i=0;i<5;i++) printf("%d ",*(a+4-i));
	printf("\n");
	
	printf("METHOD 4\n");
	for(int i=0;i<5;i++) printf("%d ",a[4-i]);
	printf("\n");

	return 0;
}

