#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int num[n+10];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	
	
	int a=num[0],cnt=0,ans=0;
	for(int i=1;i<n;i++)
	{
		//printf("%d %d\n",num[i],a);
		if(num[i]==a)
		{
			cnt++;
			a=num[i];
			if(cnt>ans) ans=cnt;
		}
		else
		{
			cnt=0;
			a=num[i];
		}
	}
	
	printf("%d\n",ans+1);

	return 0;
}

