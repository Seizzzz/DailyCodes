#include <stdio.h>
#include <stdlib.h>
/*
4
小王同学
0821131699999
87 98 79 90 68
Liu Mengmeng
0821131666666
88 90 93 91 85
Albert Einstein
0821131477777
75 87 100 66 64
Bill Gates
0821131588888
65 58 77 60 61
*/
/*
int cmp(const void* a,const void* b)
{
	return *(int*)b - *(int*)a;
}
*/

int main()
{
	int t;
	scanf("%d",&t);
	//getchar();
	
	while(t--)
	{
		char name[50];
		char id[50];
		int score[5];
		getchar();
		gets(name);
		gets(id);
		for(int i=0;i<5;i++) scanf("%d",&score[i]);
		//qsort(score,5,sizeof(score[0]),cmp);
	
		printf("Name:");
		puts(name);
		printf("ID:");
		puts(id);
		printf("Score:");
		for(int i=0;i<5;i++) printf("%d ",score[i]);
		printf("\n");
	
		int sum=score[0]+score[1]+score[2]+score[3]+score[4];
		printf("average:%.2lf ",(double)(sum)/5);
	
		printf("total:%d\n\n",sum);
	}

	return 0;
}

