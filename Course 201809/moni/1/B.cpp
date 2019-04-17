#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char a[10005];
	
	gets(a);
	int len=strlen(a);
	
	int cnt=0;
	for(int i=0;i<len;i++) if(!isdigit(a[i])) cnt++;
	
	printf("%d\n",cnt);

	return 0;
}

