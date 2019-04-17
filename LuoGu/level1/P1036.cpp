#include <stdio.h>
#include <math.h> 
#include <string.h>

int ans=0;
int rec[25]={0};

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

int cal(int n,int k,int have,int sum)
{
	if(have==k)
	{
		if(judgeprim(sum)) ans++;
		memset(rec,0,sizeof(rec));
		have=0;
		sum=0;
		
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(rec[i]==0)
			{
				sum+=num[i];
				rec[i]=1;
				have++;
				cal(n,k,have,sum);
			}
		}
	}
	
	
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int num[25];
	
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	
	cal(n,k,0,0);
	
	return 0;
}
