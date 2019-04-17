#include <stdio.h>

int f(int n)
{
	if(n>0) return f(n-1)+n*n*n+n*n;
	else if(n==0) return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",f(n));

	return 0;
}

