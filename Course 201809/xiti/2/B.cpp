#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch;
	int a=0,b=0,c=0,d=0;
	while(scanf("%c",&ch) && ch!='\n')
	{
		if(isalpha(ch)) a++;
		else if(ch==' ') b++;
		else if(isdigit(ch)) c++;
		else d++;
		
	}
	printf("%d %d %d %d\n",a,b,c,d);
	
	
	return 0;
}
