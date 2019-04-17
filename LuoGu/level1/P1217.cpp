#include <stdio.h>
#include <math.h>

int judgeprim(int n)
{
	if(n==1) return 0;
	
	int sqt=sqrt(n)+0.5;
	for(int i=2;i<=sqt;i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
}

int wei(int n,int len,int k)
{
	return (n/(int)pow(10,len-k))%10;
}

int judgereverse(int n)
{
	int len=0;
	if(n==0) len=1;
	else for(;n/(int)pow(10,len) != 0;len++);
	
	if(len%2==0 && n!=11) return 0; //偶数位数回文数一定不是质数 此处简化判断与函数名无关 
	
	for(int i=1;i<len;i++)
	{
		if(wei(n,len,i)==wei(n,len,len-i+1));
		else return 0;
	}
	return 1;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	int start;
	if(a%2==0) start=a+1;
	else start=a;
	
	for(int i=start;i<=b;i=i+2)
	{
		if(judgereverse(i))
		{
			if(judgeprim(i))
			{
				printf("%d\n",i);
			}
		}
	}

	return 0;
}

