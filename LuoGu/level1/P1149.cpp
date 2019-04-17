#include <stdio.h>
#include <math.h>

int q[10]={6,2,5,5,4,5,6,3,7,6};

int cal(int n)
{
	int len=0,count=0;
	if(n==0) len=1;
	else for(;n/(int)pow(10,len) != 0;len++);

	len--;
	
	
	while(len>=0)
	{
		count=count + *(q+((n/(int)pow(10,len--))%10));
	}

	//printf("%d\n",count);
	return count;
}

int main()
{
	
	
	int n,cnt=0;
	scanf("%d",&n);
	n-=4;
	
	for(int i=0;i<=999;i++)
	{
		for(int j=0;j<=999;j++)
		{
			int k=i+j;
			if(cal(i)+cal(j)+cal(k)==n) cnt++;
		}
	}
	
	printf("%d\n",cnt);
	
	

	return 0;
}

