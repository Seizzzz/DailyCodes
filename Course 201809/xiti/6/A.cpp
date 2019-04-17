#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n+5],b[n+5];

	int m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		a[i]=m;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		b[i]=m;
	}
	
	//for(int i=0;i<n;i++) printf("%d ",a[i]);
	
	for(int i=0;i<n;i++)
	{
		int t;
		t=a[i];
		a[i]=a[b[i]];
		a[b[i]]=t;
	}
	
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	 
	printf("\n");
	return 0;
}
/*
10
5 10 3 9 4 12 8 7 11 2
1 3 6 9 2 7 0 8 5 4
*/

