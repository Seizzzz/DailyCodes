#include <stdio.h>
#include <string.h>

int main()
{
	char a[20];
	memset(a,-1,sizeof(a));
	gets(a);
	
	char b[20],get;
	memset(a,-1,sizeof(a));
	for(int i=0;get!='\n';)
	{
		if(i%3==0 && i!=0)
		{
			b[i]=a[i];
			i++;
		}
		else
		{
			b[i]=',';
		}
	}
	
	return 0;
}
