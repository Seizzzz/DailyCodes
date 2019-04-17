#include <stdio.h>

int main()
{
	int l,c,line=1;
	scanf("%d%d",&l,&c);
	
	for(;line<=l*3+1;line++)
	{
		//
		if((line-1)%3==0)
		{
			for(int i=4*c+1;i>0;i--)
			if(i==1) printf("*\n");
				else printf("*");
		}
		//
		if((line+1)%3==0)
		{
			for(int i=c;i>0;i--)
			{
				if(i==1) printf("*$ $*\n");
				else printf("*$ $");
			}
		}
		//
		if(line%3==0)
		{
			for(int i=c;i>0;i--)
			{
				if(i==1) printf("* w *\n");
				else printf("* w ");
			}
		}
		
		
		
	}
	
	return 0;
}
