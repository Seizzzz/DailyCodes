#include <stdio.h>
#include <math.h>

int cal(int n)
{
	if(n/10 != 0)
	{
		int sum=0,len=0;
		for(;n/(int)pow(10,len);len++);
		
		for(int i=0;i<len;i++)
		{
			sum+= (n/(int)pow(10,i))%10;
		}
		cal(sum);
	}
	else return n;
}

int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		int temp;
		scanf("%d",&temp);
		printf("%d\n",cal(temp));
	}

	return 0;
}

