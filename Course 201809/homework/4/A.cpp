#include <stdio.h>

int main()
{
	char num[20],i=0;
	while(scanf("%c",&num[i])==1 && num[i]!='\n')
	{
		i++;
	}
	
	for(int j=0;j<=i-1;j++) 
	{
		if(j==i-1) printf("%c\n",num[j]);
		else printf("%c ",num[j]);
	}
	
	
	return 0;
}
