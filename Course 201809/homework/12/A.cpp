#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
	return *(int*)b - *(int*)a;
}

int main()
{
	char name[50];
	char id[50];
	int score[5];
	
	gets(name);
	gets(id);
	for(int i=0;i<5;i++) scanf("%d",&score[i]);
	qsort(score,5,sizeof(score[0]),cmp);
	
	printf("Name:");
	puts(name);
	printf("ID:");
	puts(id);
	printf("Score:");
	for(int i=0;i<5;i++) printf("%d ",score[i]);
	printf("\n");
	
	int sum=score[0]+score[1]+score[2]+score[3]+score[4];
	printf("average:%.2lf ",(double)(sum)/5);
	
	printf("total:%d\n",sum);

	return 0;
}

