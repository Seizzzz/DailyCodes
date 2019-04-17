#include <stdio.h>
#include <math.h>

int n,k,ans=0,num[25],rec[25]={0};

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

void cal(int x,int have,int sum)
{
	if(have==k)
	{
		if(judgeprim(sum)) ans++;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(rec[i]==0 && i>x)
			{
				rec[i]=1;
				cal(i,have+1,sum+num[i]);
				rec[i]=0;
			}
		}
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	
	cal(0,0,0);
	
	printf("%d\n",ans);
	
	return 0;
}
