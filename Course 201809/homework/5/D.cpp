#include <stdio.h>

int main()
{
	long long int n,sum=0;
	scanf("%lld",&n);
	
	for(long long int s1=1;s1<=n-2;s1++)
	{
		for(long long int s2=1;s2<=n-2;s2++)
		{
			for(long long int s3=n-s1-s2;s3<=n-2;s3++)
			{
				if(s1+s2>s3 && s1+s3>s2 && s2+s3>s1 && s1+s2+s3==n && s1<=s2 && s2<=s3)
				{
					printf("%d %d %d\n",s1,s2,s3);
					sum++;
				}
			}
		}
	}
	printf("%lld\n",sum);
	
	
	return 0;
}
