#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int ji[n+2], ou[n+2];
	int jicnt=0,oucnt=0;
	int temp;
	
	while(n--)
	{
		scanf("%d",&temp);
		if(temp%2==0)
		{
			ou[oucnt]=temp;
			oucnt++;
		}
		else
		{
			ji[jicnt]=temp;
			jicnt++;
		}
	}
	
	qsort(ji,jicnt,sizeof(ji[0]),cmp);
	qsort(ou,oucnt,sizeof(ou[0]),cmp);
	
	for(int i=0;i<jicnt;i++) printf("%d ",ji[i]);
	for(int i=0;i<oucnt;i++) printf("%d ",ou[i]);
	
	printf("\n");

	return 0;
}

