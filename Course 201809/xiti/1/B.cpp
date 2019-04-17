#include <stdio.h>

int main()
{
	int t,n,a;
	scanf("%d",&t);
	for(;t>0;t--)
	{
		scanf("%d",&a);
		int sum=0;
		for(;a>0;a--)
		{
			scanf("%d",&n);
			sum+=n;
		}
		if(sum>=400) printf("%d\n",sum-160);
		else if(sum>=300) printf("%d\n",sum-110);
		else if(sum>=200) printf("%d\n",sum-70);
		else if(sum>=100) printf("%d\n",sum-30);
		else printf("%d\n",sum);
	}
	
	return 0;
}
