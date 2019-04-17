#include <stdio.h>

int main()
{
	long long int a,b;
	char c;
	scanf("%c%lld%lld",&c,&a,&b);
	
	if(c=='A'||c=='a') printf("%lld",a+b);
	else if(c=='S'||c=='s') printf("%lld",a-b);
	else if(c=='M'||c=='m') printf("%lld",a*b);
	else if(c=='D'||c=='d') printf("%lld",a/b);
	else if(c=='R'||c=='r') printf("%lld",a%b);
	else printf("error");
	
	return 0;
}
