#include <stdio.h>
#include <string.h>
#define maxn 100005

int ans[maxn];


int main()
{
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=maxn;i++)
	{
		int k=i;
		int sum=i;
		while(k>0)
		{
			sum+=k%10;
			k/=10;
		}
		
		if(ans[sum]==0 || i<ans[sum]) ans[sum]=i;
	}
	
	int t,n;
	scanf("%d",&t);
	//printf("%d\n",t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	
	return 0;
}
