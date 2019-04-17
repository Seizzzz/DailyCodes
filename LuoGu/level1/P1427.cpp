#include <stdio.h>
#include <string.h>

int main()
{
	long long int a[105];
	memset(a,6,sizeof(a));
	
	
	int i=1;
	while(scanf("%lld",&a[i]) && a[i]!=0) i++;
	i--;
	
	for(;i>=1;i--) printf("%lld ",a[i]);
	
	return 0;
}
