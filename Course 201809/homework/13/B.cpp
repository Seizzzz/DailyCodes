#include <stdio.h>
#include <string.h>

int main()
{
	char a[105];
	gets(a);
	
	char b;
	scanf("%c",&b);
	
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]==b);
		else printf("%c",a[i]);
	}
	
	printf("\n");

	return 0;
}

