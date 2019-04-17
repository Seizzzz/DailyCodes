#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/*
4
Where there is hope ,there is a way.
Welcome Beijing.
Nice idea.
Have fun.
*/

int cmp(const void *a,const void *b )
{
	return strcmp((char*)b,(char*)a);
}

int main()
{
	int t;
	scanf("%d",&t);
	char a[t][100005];
	getchar();
	
	for(int i=0;i<t;i++)
	{
		char c='\0';
		for(int j=0;c!='\n';j++)
		{
			c=getchar();
			a[i][j]=c;
		}
	}
	
	qsort(a[0],t,sizeof(a[0]),cmp);
	
	//for(int i=0;i<t;i++) printf("%s\n",a[i]);
	
	for(int i=t-1;i>=0;i--)
	{
		int len=strlen(a[i]);
		for(int j=0;j<len;j++) printf("%c",a[i][j]);
		//printf("\n");
	}
	return 0;
}

