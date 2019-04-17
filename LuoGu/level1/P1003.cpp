#include <stdio.h>
int ground[100005][100005];

int main()
{
	
	int n;
	scanf("%d",&n);
	
	long long a,b,g,k;
	
	for(;n>0;n--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&g,&k);
		
		for(int delta1=a;delta1<=a+g;delta1++)
		{
			for(int delta2=b;delta2<=b+k;delta2++)
			{
				ground[delta1][delta2]++;
			}
		}
	}
	
	long long p,q;
	scanf("%lld%lld",&p,&q);
	
	if(ground[p][q]==0) printf("-1\n");
	else printf("%lld\n",ground[p][q]);

	//printf("%lld",ground[p][q]);
	//printf("%lld",ground[p][q]==0? n-1:ground[p][q]);
	
}
