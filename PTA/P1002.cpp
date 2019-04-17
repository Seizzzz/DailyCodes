#include <stdio.h>
#include <math.h>

int main()
{
	char c;
	long long sum=0;
	while((c=getchar())!='\n')
	{
		sum+=c-'0';
	}

	int len=0;
	for(;sum/(int)pow(10,len) != 0;len++);
	
	for(int i=len-1;i>=0;i--)
	{
		switch((sum/(int)pow(10,i)) % 10)
		{
			case 0: printf("ling"); break;
			case 1: printf("yi"); break;
			case 2: printf("er"); break;
			case 3: printf("san"); break;
			case 4: printf("si"); break;
			case 5: printf("wu"); break;
			case 6: printf("liu"); break;
			case 7: printf("qi"); break;
			case 8: printf("ba"); break;
			case 9: printf("jiu"); break;
		}
		if(i) printf(" ");
	}
	printf("\n");
	
	return 0;
}
