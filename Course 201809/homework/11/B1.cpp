#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char *start[1010],text[10020];
	int i,j=1;
	gets(text);
	if(text[0]==' ')
	{
		for(i=0;text[i]==' ';i++)
		{
			if(text[i]==' ')
			  text[i]='\0';
		}
		start[0]=text+i;
	}
	else
		start[0]=text;

	for(i;text[i];i++)
	{
		if(text[i]==' ')
		  text[i]='\0';
		if(text[i+1]!='\0'&&text[i]=='\0')
		  start[j++]=&text[i+1];
	}
	
	int k=0;
	
	for(i=0;i<j;i++)
	{
		for(k=0;*(start[i]+k);k++) printf("%c",*(start[i]+k));
		if(*(start[i]+k)=='\0'&&*(start[i]+k+1)!='\0') printf("\n");
	}
	printf("\n");
	return 0;
}

