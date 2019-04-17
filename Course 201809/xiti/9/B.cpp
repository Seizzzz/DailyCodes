#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	//getchar();
	
	while(n--)
	{
		char temp[65];
		scanf("%s",temp);
		
		if(isalpha(temp[0]) || temp[0]=='_')
		{
			int len=strlen(temp);
			if(len<=50)
			{
				int flag=0;
				for(int i=1;i<len;i++)
				{
					if(isdigit(temp[i]) || isalpha(temp[i]) || temp[i]=='_');
					else
					{
						flag++;
						printf("no\n");
						break;
					}
				}
				if(flag==0) printf("yes\n");
			}
			else printf("no\n");
		}
		else printf("no\n");
	}

	return 0;
}

