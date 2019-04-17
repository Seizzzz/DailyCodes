#include <stdio.h>
#include <ctype.h>

int main()
{
	char temp, num[15];
	int j=0;
	for(int i=1;i<=13;i++)
	{
		scanf("%c",&temp);
		if(isdigit(temp)||temp=='X') num[j++]=temp;
	}
	
	int sum=0;
	for(int i=0;i<=8;i++)
	{
		sum+=((int)(num[i]-'0')*(i+1));
	}
	
	if(sum%11==10)
	{
		if(num[9]=='X') printf("Right\n");
		else
		{
		printf("%c-",num[0]);
		for(int i=1;i<=3;i++) printf("%c",num[i]);
		printf("-");
		for(int i=4;i<=8;i++) printf("%c",num[i]);
		printf("-");
		printf("X\n");
		}
	}
	
	if(sum%11!=10)
	{
		if(sum%11==((int)(num[9]-'0'))) printf("Right\n");
		else
		{
		printf("%c-",num[0]);
		for(int i=1;i<=3;i++) printf("%c",num[i]);
		printf("-");
		for(int i=4;i<=8;i++) printf("%c",num[i]);
		printf("-");
		printf("%d\n",sum%11);
		}
	}

	return 0;
}
