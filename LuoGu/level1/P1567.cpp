#include <stdio.h>

int main()
{
	long long int N;
	scanf("%lld",&N);
	long long int data[N];
	for(long long int i=1;i<=N;i++) scanf("%lld",&data[i]);
	
	long long int record=0,temp,recordtemp=0;
	
	for(temp=1;temp<=N;temp++)
	{
		if(temp+1>N) break;
		if(data[temp+1]>data[temp])
		{
			recordtemp++;
			if(recordtemp>record) record=recordtemp;
		}
		else recordtemp=0;
	}
	
	printf("%lld",record+1);
	
	return 0;
}
