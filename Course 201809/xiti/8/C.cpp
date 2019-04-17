#include <stdio.h>
#include <string.h>

/*
dhd dhdhdfg dhd dh zx67 dhd mklodhdh
dhd
*/

int main()
{
	char text[105],word[105];
	gets(text);
	gets(word);
	
	int lentext=strlen(text),lenword=strlen(word);
	
	int ans=0;
	for(int i=0;i<lentext;i++)
	{
		int flag=0;
		for(int j=0;j<lenword;j++)
		{
			if(text[i+j]==word[j]);
			else
			{
				flag++;
				break;
			}
		}
		if(flag==0) ans++;
	}
	
	printf("%d\n",ans);

	return 0;
}

