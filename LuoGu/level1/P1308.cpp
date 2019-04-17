#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char sv[1000005],word[15],text[1000005];
int p=0,p1=0,first=1,count=0,svfirst;

long long find(long long n)
{
	for(;text[n]!=' ';n++);
	return n;
}

int main()
{

	gets(word);
	gets(text);
	
	//Сд 
	for(int i=0;i<=strlen(word);i++)
	{
		if(isupper(word[i])) text[i]=tolower(word[i]);
	}
	for(int i=0;i<=strlen(text);i++)
	{
		if(isupper(text[i])) text[i]=tolower(text[i]);
	}
	//
	
	while(p!=-1)
	{
		if(text[p]==' ') p++;
		p1=find(p);
		
		sv=str.substr(p,p1-1);
		
		if(!strcmp(sv,word)) count++;
		
		if(first)
		{
			first=0;
			svfirst=p;
		}
	}
	
	printf("%d %d\n",count,svfirst);

	
	
	
	return 0;
}

/*int main()
{
	char word[15];
	gets(word);
	char text[1000005];
	gets(text);
	
	for(int i=0;i<=strlen(word);i++)
	{
		if(isupper(word[i])) text[i]=tolower(word[i]);
	}
	for(int i=0;i<=strlen(text);i++)
	{
		if(isupper(text[i])) text[i]=tolower(text[i]);
	}
	
	int len_word=strlen(word);
	
	for(int i=0;i<=strlen(text);i++)
	{
	if(0) a: continue;
	
		for(int j=i;j<=strlen(text);j++)
		{
			if(text[j]==' ')
			{
				if(j-i==len_word)
				{
					int correct=0,count=0;
					for(int test=i;i<=j;i++)
					{
						printf("%c %c\n",text[i],word[count]);
						if(text[i]==word[count])
						{
							count++;
						}
						else correct++;
						
						//printf("%d",correct);
						if(!correct) printf("yes ");
					}
					//for(int test=i;i<=j;i++) printf("*%c*",text[i]);
					//printf("yes");
				}
				else
				{
					i=j;
					goto a;
				}
			}
			else continue;
		}
	}
	
	
	
	return 0;
}*/
