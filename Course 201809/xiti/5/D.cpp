#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	int maxx=(c/a)+1,maxy=(c/b)+1;
	
	int cnt=0;
	for(int i=0;i<=maxx;i++)
	{
		for(int j=0;j<=maxy;j++)
		{
			if(a*i+b*j==c) cnt++;
		}
	}
	
	printf("%d\n",cnt);

	return 0;
}

