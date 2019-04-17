#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
5
bbb
zzzzzz
aabbbccc
aaaaaa
abbbbb
*/

/*
3
abbbbbb
abbbbbb
aaaa
*/

int main()
{
	int n;
	scanf("%d",&n);

	char a[n+5][105];
	getchar();
	
	for(int i=0;i<n;i++) gets(a[i]);
	
	int flag=1;
	char temp[105];
	
	while(flag)
	{
		flag=0;
		
		for(int i=0;i<n-1;i++)
		{
			if(strcmp(a[i],a[i+1])>0)
			{
				strcpy(temp,a[i]);
				strcpy(a[i],a[i+1]);
				strcpy(a[i+1],temp);
				flag++;
			}
		}
	}
	
	for(int i=0;i<n;i++) puts(a[i]);
	


	return 0;
}

