#include <stdio.h>
#include <math.h>

int main()
{
	long long int n,T,s,s1;
	scanf("%d",&T);
	
	for(;T>0;T--)
	{
		scanf("%lld",&n);
		s1=s=n%10;
		for(int i=n;i>1;i--)
		{
			s*=s1;
			s=s%10;
		}
		printf("%d\n",s%10);
	}
	
	return 0;
}
