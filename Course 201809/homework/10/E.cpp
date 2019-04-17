#include <stdio.h>
#include <string.h>


int main()
{
	int n;
	scanf("%d",&n);
	
	int a[2*n+5];
	int b[2*n+5];
	
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	if(n==2)
	{
		printf("1 2\n");
		return 0;
	}
	if(n==3)
	{
		printf("1 2 3\n");
		return 0;
	}
	
	a[1]=n-2;
	a[2]=n-1;
	a[3]=n;
	int cnt=3;
	
	while(a[1]>1)
	{
	for(int i=1;i<=cnt+2;i++)
	{
		b[i+2]=a[i];
	}
	for(int i=1;a[i+cnt-2]!=0;i++)
	{
		b[i]=b[cnt+i];
	}
	b[0]=n-cnt;
	for(int i=1;i<=cnt+1;i++) a[i]=b[i-1];
	cnt++;
	}
	
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}

