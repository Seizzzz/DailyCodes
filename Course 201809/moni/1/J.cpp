#include <stdio.h>
#include <string.h>

int main()
{
	char a[12];
	gets(a);
	
	int t,alen=strlen(a);
	scanf("%d",&t);
	getchar();
	
	while(t--)
	{
		char temp[12];
		gets(temp);
		int templen=strlen(temp);
		int j=0;
		for(int i=0;i<alen;i++)
		{
			for(;j<templen;j++)
			{
				if(a[i]==temp[j])
				{
					j++; 
					goto suc;
				}
			}
			
			goto fail;
			
			suc:{}
		}
		
		puts(temp);
		
		fail:{};
	}

	return 0;
}

