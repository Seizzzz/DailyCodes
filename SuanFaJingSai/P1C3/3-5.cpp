#include <stdio.h>
#include <math.h>

//int ans[100005];

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<n;i++)
	{
		int len=0;
		for(;i/(int)pow(10,len);len++);
		len--;
		
		int sum=0;
		do
		{
			sum+= (i/(int)pow(10,len))%10;
			len--;
		}
		while(len>=0);
		
		//printf("%d %d\n",sum,i);
		if(sum+i==n)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("0\n");
	
	return 0;
}
