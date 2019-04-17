#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n+10];
	
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int num,ans=0;
		scanf("%d",&num);
		for(int i=0;i<n;i++)
		{
			if(a[i] == num)
			{
				ans++;
				if(i==0) printf("%d\n",a[i+1]);
				else if(i==n-1) printf("%d\n",a[i-1]);
				else printf("%d %d\n",a[i-1],a[i+1]);
			}
		}
		if(ans==0) printf("NULL\n");
	}

	return 0;
}
