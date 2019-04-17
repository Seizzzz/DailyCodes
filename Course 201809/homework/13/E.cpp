#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
10
Bb b
zzz zzz
aab bbccc
aaabbaaa
abb bbb
ccidfjD
Aidj idj
Ccidf jD
sidfjijE EE
kkkkkk
*/

int cmp(const void* a,const void* b)
{
	return strcmp((char*)a ,(char*)b);
}

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	
	char a[n][1002];
	
	for(int i=0;i<n;i++)
	{
		gets(a[i]);
	}
	
	qsort(a[0],n,sizeof(a[0]),cmp);
	
	for(int i=0;i<n;i++)
	{
		puts(a[i]);
	}
	
	

	return 0;
}

