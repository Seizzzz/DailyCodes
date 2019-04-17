#include <stdio.h>

int main()
{
	int max;
	scanf("%d",&max);
	
	for(int i=max;;i++)
	{
		if(i%5==1 && i%6==5 && i%7==6 && i%11==10)
		{
			printf("%d\n",i);
			break;
		}
	}
	
	
	return 0;
}
