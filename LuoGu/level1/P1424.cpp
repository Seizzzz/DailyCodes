#include <stdio.h>

int main()
{
	long long int x,n;
	scanf("%lld%lld",&x,&n);
	
	long long int firstweek=0;
	if(x==6 || x==7) firstweek=0;
	else if(x+n+1<=5) firstweek+=250*n;
	else firstweek+=(5-x+1)*250;
	
	long long int full=0;
	if(x+n<=8) full=0;
	else full+=((x+n-8)/7)*1250;
	
	long long int last=0;
	if((x+n-8)%7>5) last+=1250;
	else last+=((x+n-8)%7)*250;
	
	printf("%lld",firstweek+full+last);
	
		
	return 0;
}
