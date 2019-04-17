#include <stdio.h>
#include <string.h>

int main()
{
	char text[10005];
	
	int c,i=0;
	gets(text);
    /*while((c=getchar())!='\n') text[i++]=c;
    text[i]='\0';*/
	
	
	char* start=text;
	int len=0;
	
	int strlentext=strlen(text);
	text[strlentext]=' '; //´¦ÀíÄ©Î²Îª' ' 
	
	while(start-text+len<=strlentext+1)
	{
		//printf("%c",*start);
		while((*start)==' ') start++;
		
		for(len=0;text[start-text+len]!=' ';len++);
		text[start-text+len]='\0';
		
		for(int i=0;i<len;i++) printf("%c",*(start+i));
		
		printf("\n");
		//printf("%d",start-text+len);
		
		start+=len+1;
	}

	return 0;
}

