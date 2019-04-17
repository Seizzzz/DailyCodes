#include <stdio.h>
#include <string.h>

int main()
{
	char cnum[20];
	gets(cnum);
	
	int minus=0;
	
	if(cnum[0]=='-') minus=1;
	
	int lennum=strlen(cnum);
	
	int num[20];
	for(int i=(minus)? 1:0;i<lennum;i++) num[i]=cnum[i]-'0';
	
	
	//i> (minus)? 0:-1
	int zero=0;
	if(minus) printf("-");
	if(num[0]==0 && lennum==1)
	{
		printf("0\n");
		return 0;
	}
	
	for(int i=lennum-1 ; i>=(minus)? 1:0 ; i--)
	{
		if(zero==0)
		{
			if(num[i]==0);
			else
			{
				zero=1;
				printf("%d",num[i]);
			}
		}
		else printf("%d",num[i]);
	}
	
	printf("\n");

	return 0;
}

