#include <stdio.h>
#include <string.h>

char* search(char* str1,char* str2,int len,int len1)
{
	for(int i=0;i<len1;i++)
	{
		int flag=0;
		int poz=0;
		for(int j=i;j<i+len1-1;j++)
		{
			//int poz=0;
			if(str1[j]==str2[poz]);
			else
			{
				flag++;
				break;
			}
			
			poz++;
		}
		if(flag==0)
		{
			for(int pr=i;pr<len1-1;pr++)
			{
				printf("%c",str1[pr]);
			}
			printf("\n");
			return 0;
		}
	}
}

int main()
{
	char str1[505],str2[505];
	char temp='\0';
	for(int i=0;temp!='\n';i++) str1[i]=(temp=getchar());
	temp='\0';
	for(int i=0;temp!='\n';i++) str2[i]=(temp=getchar());
	
	//char* start=search(str1,str2,strlen(str1),strlen(str2));
	//printf("%p",start);
	
	search(str1,str2,strlen(str1),strlen(str2));
	return 0;
}

