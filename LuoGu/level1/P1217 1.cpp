#include <stdio.h>
#include <math.h>

int judgeprim(int n)
{
	int sqt=sqrt(n)+0.5;
	for(int i=2;i<=sqt;i++)
	{
		if(n%i==0) return 0;
	}
	
	if(n<=1) return 0;
	return 1;
}

int gz(int n)
{
	int len=0;
	if(n==0) len=1;
	else for(;n/(int)pow(10,len) != 0;len++);
	
	char temp[10];
	int t=len-1;
	
	for(int i=1;i<=len;i++)
	{
		temp[i]=(n/(int)pow(10,t--))%10;
	}
	
	int max=2*len;
	for(int i=len+1;i<=max;i++)
	{
		temp[i]=temp[max-i];
	}
	
	int sum=0; 
	max-=2;
	for(int i=1;max>=0;i++)
	{
		sum+= temp[i] * (int)pow(10,max--);
	}
	
	return sum;
}


int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	for(int i=1;gz(i)<=a;i++)
	{
		int a=-1;
		for(;a<=b;i++)
		{
			a=gz(i);
			if(judgeprim(a)) printf("%d\n",a);
		}
		break;
	}
	
	

	return 0;
}

