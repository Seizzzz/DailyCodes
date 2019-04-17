#include <stdio.h>

void prnt(int n)
{
	int i;
	for(i=1;n>i;i++) n=n-i;
	
	if(i%2) printf("%d/%d\n",i-n+1,n);
	else printf("%d/%d\n",n,i-n+1);
}

int main()
{
	int n;
	scanf("%d",&n); 
	
	prnt(n);
	
	return 0;
}

