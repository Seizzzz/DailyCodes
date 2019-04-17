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

int cmp(const void* a,const void* b)
{
	return strcmp((char*)b,(char*)a);
}

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	
	char** a=(char**)malloc(sizeof(char*) * n);
	
	char temp[100005];
	
	for(int i=0;i<n;i++)
	{
		gets(temp);
		a[i]=(char*)malloc(sizeof(char) * strlen(temp));
		strcpy(a[i],temp);
	}
	
	qsort(*(a+0),n,2,cmp);
	
	for(int i=0;i<n;i++) puts(a[i]);
	

	return 0;
}

