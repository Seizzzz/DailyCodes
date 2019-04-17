#include <stdio.h>

int main()
{
	char c;
	while((c=getchar())!='\n')
	printf("%c", ((c>='a'&&c<'x')||(c>='A'&c<'X'))? c+=3:c-=23); 
	
	return 0;
}
