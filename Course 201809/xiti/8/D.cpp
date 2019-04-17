#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
20130410Bupt
*/
int main()
{
	char temp[52];
	temp[0]='\0';
	while(1)
	{
		scanf("%s",temp);
		if(temp[0]=='E'&&temp[1]=='N'&&temp[2]=='D'&&temp[3]=='\0') break;
		int lentemp=strlen(temp);
		if(lentemp<8) printf("NO\n");
		else
		{
			int zu1=0,zu2=0,zu3=0,zu4=0;
			for(int i=0;i<lentemp;i++)
			{
				if(isdigit(temp[i])) zu3=1;
				else if(isalpha(temp[i]))
				{
					if(temp[i]>='A' && temp[i]<='Z') zu1=1;
					else zu2=1;
				}
				else zu4=1;	
					//if(temp[i]=='~' || temp[i]=='!' || temp[i]=='@' || temp[i]=='#' || temp[i]=='$' || temp[i]=='%' || temp[i]=='^' || temp[i]=='&' || temp[i]=='*' || temp[i]=='(' || temp[i]==')' || temp[i]=='-' || temp[i]=='=');				
			}
			if(zu1+zu2+zu3+zu4<3) printf("NO\n");
			else printf("YES\n");
			
		}
		
	}

	return 0;
}

