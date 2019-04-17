#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define cmass 12.01
#define hmass 1.008
#define omass 16.00
#define nmass 14.01

int main()
{
	char s[100];
	scanf("%s",s);
	
	double sum=0;
	for(int i=0;i<strlen(s);)
	{
		if(isdigit(s[i+1]-'0') && isdigit(s[i+2]-'0'))
		{
			int amount=10*(s[i+1]-'0')*(s[i+2]-'0');
			
			if(s[i]=='C') sum += amount*cmass;
			else if(s[i]=='H') sum += amount*hmass;
			else if(s[i]=='O') sum += amount*omass;
			else sum += amount*nmass;
			i=i+3;
		}
		else if(isdigit(s[i+1]-'0'))
		{
			int amount=s[i+2]-'0';	
			if(s[i]=='C') sum += amount*cmass;
			else if(s[i]=='H') sum += amount*hmass;
			else if(s[i]=='O') sum += amount*omass;
			else sum += amount*nmass;
			i=i+2;
		}
		else
		{
			if(s[i]=='C') sum += cmass;
			else if(s[i]=='H') sum += hmass;
			else if(s[i]=='O') sum += omass;
			else sum += nmass;
			i=i+1;
		}
	}
	
	printf("%lf",sum);
	
	return 0;
}
