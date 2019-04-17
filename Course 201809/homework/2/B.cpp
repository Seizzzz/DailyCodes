#include <stdio.h>

int main()
{
	char a,b,c;
	scanf("%c%c%c",&a,&b,&c);
	if (((a>=65 && a<=90) || (a>=97 && a<=122)) && ((b>=65 && b<=90) || (b>=97 && b<=122)) &&((c>=65 && c<=90) || (c>=97 && c<=122)))
	{
		if((a-b==1&&b-c==1) || (a-b==-1&&b-c==-1))
		{
			printf("Yes");
		}
		else
		{
		printf("No");
		}
	}
	else
	{
		printf("No");
	}

}
