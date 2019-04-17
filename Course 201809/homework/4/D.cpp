#include <stdio.h>
#include <math.h>

int main()
{
	long long int a,b,c,cnt=1;
	scanf("%lld%lld%lld",&a,&b,&c);
	
	for(long long int i=a;i<=b;i++)
	{
		long long int sum=0;
		
		for(long long int j=1;j<i;j++)
		{
			//printf("%d ",sum);
			if(i%j==0) sum+=j;
		}
		if(fabs(i-sum)<=c) 
		{
			if(cnt%5==0) printf("%lld\n",sum);
			else printf("%lld\t",sum);
			cnt++;
		}
	}
	if(cnt==1) printf("There is no proper number in the interval.\n");
	else printf("\n");
	
	return 0;
} 
