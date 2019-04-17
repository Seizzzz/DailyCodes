#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void sort(char a[][20],int n)//Ã°ÅÝÅÅÐò
{
	int loc=n-1;
	char b[210];
	int i;
	for(loc=n-1;loc>=1;loc--)
	{
		for(i=0;i<loc;i++)
		{
			if(strcmp(a[i],a[i+1])>0)
			{
				strcpy(b,a[i]);
				strcpy(a[i],a[i+1]);
				strcpy(a[i+1],b);
			}
		}
	}
}

int main()
{
	char st1[20];
	int n,i,j;
	
	gets(st1);
	
	scanf("%d",&n);
	
	char st2[n][20];
	for(i=0;i<n;i++) scanf("%s",st2[i]);
	
	char st3[n][20];
	
	
	int loc=0,count=0;
	
	for(i=0;i<n;i++)
	{
		for(j=0,loc=0;st2[i][j];j++)
		{
			if(st2[i][j]==st1[loc]&&st1[loc]) loc++;
		}
		if(st1[loc]=='\0') strcpy(st3[count++],st2[i]);
	}
	
	sort(st3,count);
	for(i=0;i<count;i++) puts(st3[i]);
	  
}
 

