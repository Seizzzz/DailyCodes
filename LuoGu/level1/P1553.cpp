#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char a[100];
	gets(a);
	int special=0;
	
	for(int i=0;i<strlen(a);i++)
	{
		if(isdigit(a[i]));
		else special=1;
	}
	//
	//
	if(special==0)
	{
		int test0=0,count=strlen(a)-1;
		for(int h=strlen(a)-1;a[h]=='0';h--)
		{
			if(!test0) count--;
			else break;
		}
		for(int i=count;i>=0;i--) printf("%c",a[i]);
	}
	
	else
	{
		int j;
		for(j=0;isdigit(a[j]);j++);
		//
		int test1=0;
		for(int h=j-1;h>=0;h--)
		{
			if(a[h]=='0' && !test1);
			else
			{
				printf("%c",a[h]);
				test1++;
			}
		}
		if(test1==0) printf("0");
		//
		printf("%c",a[j]);
		//
		
		int test2=0,count=j+1;
		for(int h=j+1;h<=strlen(a)-1;h++)
		{
			if(a[h]=='0' && !test2) count++;
			else test2++;
		}
		
		int test3=0,count1=strlen(a)-1;
		for(int h=strlen(a)-1;!a[h];h--)
		{
			if(a[h]=='0' && !test3) count--;
			else test3++;
		}
		
		if(test2==0 && a[j]!='%') printf("0");
		else
		{
			if(a[j]=='.')
			{
				for(int h=count1;h>=count;h--)
				{
					printf("%c",a[h]);
				}
			}
			else if(a[j]=='/')
			{
				/*if(a[count1]!=0)
				{
					for(int h=count1;h>=j+1;h--)
					{
					printf("%c",a[h]);
					}
				}
				else */for(int h=count1-1;h>=j+1;h--)
				{
					printf("%c",a[h]);
				}
			}
			
			else
			{
				for(int h=count1-1;h>=count;h--)
				{
					printf("%c",a[h]);
				}
			}
		}
		
	}
	
	printf("\n");
	
	
	return 0;
}
