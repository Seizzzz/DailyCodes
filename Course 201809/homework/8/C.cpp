#include <stdio.h>

int main()
{
	int ou[205],ji[205];
	
	int n;
	scanf("%d",&n);
	
	int cntou=0,cntji=0;
	while(n--)
	{
		int t;
		scanf("%d",&t);
		if(t%2==0)
		{
			ou[cntou]=t;
			cntou++;
		}
		else
		{
			ji[cntji]=t;
			cntji++;
		}
	}
	
	for(int i=0;i<cntou;i++)
	{
		printf("%d ",ou[i]);
	}
	for(int i=0;i<cntji;i++)
	{
		printf("%d ",ji[i]);
	}
	
	printf("\n");

	return 0;
}

