#include <stdio.h>

int main()
{
	char c,combo=0,sum=0;
	while((c=getchar())!='\n')
	{
		if(c=='X') combo=0;
		else
		{
			combo++;
			sum+=combo;
		}
	}
	printf("%d\n",sum);
	return 0;
}
