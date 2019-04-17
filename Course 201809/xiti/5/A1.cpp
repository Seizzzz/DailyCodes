#include <stdio.h>

int main()
{
	long long n;
	scanf("%lld",&n);
	
	if(n==0)
	{
		printf("1\n");
		return 0;
	}
	
	long long a[100],i=0,c=0;
	while(n!=0)
	{
		i=n%2;
		a[c]=i;
		c++;
		n=n/2;
	}
	c--;
	
	printf("%d\n",c+1);

	return 0;
}

