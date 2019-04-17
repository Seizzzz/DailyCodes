#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int a[n+2];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int temp;
		scanf("%d",&temp);
		
		for(int i=0;i<n;i++)
		{
			if(a[i]==temp)
			{
				if(i==0) printf("%d\n",a[1]);
				else if(i==n-1) printf("%d\n",a[n-2]);
				else printf("%d %d\n",a[i-1],a[i+1]);
				
				break;
			}
			if(i==n-1) printf("NULL\n");
		}
	}

	return 0;
}

