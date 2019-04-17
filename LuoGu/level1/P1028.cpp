#include <stdio.h>

int count=0;

void judge(int n)
{
	count++;
	if(n==1) return;

	for(int i=n/2;i>=1;i--)
	{
		//printf("%d\n",i);
		judge(i);
		
	}
	
	return;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	judge(n);
	
	printf("%d\n",count);
	
	return 0;
}
