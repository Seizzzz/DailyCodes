#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char text[1000005],word[15]={'\0'},temp[15]={'\0'};
	
	long long cnt=0,pzt=-1;
	
	/*
	To
	TO be or not to be is a question
	*/
	
	//scanf("%s",word);
	char c;
	for(long long i=0;(c=getchar())!='\n';i++) word[i]=c;
	for(long long i=0;(c=getchar())!='\n';i++) text[i]=c;
	
	for(long long i=0;i<strlen(word);i++)
	{
		if(isupper(word[i])) word[i]=tolower(word[i]);
	}
	for(long long i=0;i<strlen(text);i++)
	{
		if(isupper(text[i])) text[i]=tolower(text[i]);
	}
	
	//puts(word);
	//puts(text);
	
	
	text[strlen(text)]= ' ';
	long long point=0;
	while(point<strlen(text))
	{
		long long tempoint=0;
		memset(temp,'\0',sizeof(temp));
		
		while(text[point] != ' ')
		{
			if(tempoint > strlen(word))
			{
				while(text[point]!=' ') point++;
				break;
			}
			
			temp[tempoint]=text[point];
			
			if(word[tempoint] == temp[tempoint]);
			else
			{
				while(text[point]!=' ') point++;
				break;
			}
			//printf("%c %c\n",temp[tempoint],text[point]);
			
			point++;
			tempoint++;
		}
		
		if(strcmp(temp,word)==0) 
		{
			if(pzt==-1) pzt=point-tempoint;
			cnt++;
		}
		
		point++;
	}
	
	if(cnt==0) printf("-1\n");
	else
	{
		printf("%lld %lld\n",cnt,pzt);
	}

	return 0;
}

