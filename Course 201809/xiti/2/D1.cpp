#include <stdio.h>
#include <string.h>

int main()
{
	char a[20];
	memset(a,-1,sizeof(a));
	int i,j;
	
	
	scanf("%20s",a);
	
	if(strlen(a)<=3)
	{
		puts(a);
		return 0;
	}
	
	
	for (i = 0; i<strlen(a)%3; i++) 
	{
		putchar(a[i]);
	}
	
	if(i!=0) putchar(',');
	for (j=0; i<strlen(a); i++)
	{
		putchar(a[i]);
		if (++j%3==0&&i!=strlen(a)-1)
		{
		printf(","); 
		}
	}
	printf("\n"); 
	return 0;
}
