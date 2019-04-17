#include <stdio.h>

int j(int n)
{
	if(n>=0 && n<=255) return 1;
	else return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		int a,b,c,d;
		scanf("%3d.%3d.%3d.%3d",&a,&b,&c,&d);
		
		
		
		if(j(a) && j(b) && j(c) && j(d)) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}

