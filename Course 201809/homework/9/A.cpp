#include <stdio.h>
#include <string.h>

int main()
{
	char c,a[105];
	
	gets(a);
	
	scanf("%c",&c);
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]!=c) printf("%c",a[i]);
	}

	printf("\n");
	return 0;
}

