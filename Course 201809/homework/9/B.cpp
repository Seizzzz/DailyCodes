#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
IlovelanguageC
OPDGHSTABNRYZCQJKLMIXEFUVW
hpzaeongxrbcljwtskfymdqiuv
*/

int main()
{
	char temp[105],da[30],xiao[30];
	
	gets(temp);
	gets(da);
	gets(xiao);
	
	for(int i=0;i<strlen(temp);i++)
	{
		if(temp[i]=='z' || temp[i]=='Z') temp[i]=temp[i]-25;
		else temp[i]= temp[i]+1;
	}
	
	for(int i=0;i<strlen(temp);i++)
	{
		if(isupper(temp[i]))
		{
			printf("%c",da[temp[i]-'A']);
		}
		else
		{
			printf("%c",xiao[temp[i]-'a']);
		}
	}
	
	printf("\n");

	return 0;
}

