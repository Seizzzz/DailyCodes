#include <stdio.h>
#include <string.h>

void getline_(char s[])
{
    int c,i=0;
    while((c=getchar())!='\n') s[i++]=c;
    s[i]='\0';
	return;
}

char* search(char* str1,char* str2,int len1,int len2)
{
	for(int i=0;i<len1;i++)
	{
		int flag=0;
		for(int j=i;j-i<len2;j++)
		{
			if(str1[j]==str2[j-i]);
			else
			{
				flag++;
				break;
			}
		}
		if(flag==0) return str1+i;
	}
	return str2;
}

int main()
{
	char str1[505],str2[505];
	getline_(str1);
	getline_(str2);
	
	char* start=search(str1,str2,strlen(str1),strlen(str2));
	if(start==str2)
	{
		printf("NULL!\n");
		return 0;
	}
	//printf("%p",start);
	char* end=&str1[strlen(str1)];
	
	for(char* i=start;i<end;i++) printf("%c",*i);
	printf("\n");
	
	return 0;
}

