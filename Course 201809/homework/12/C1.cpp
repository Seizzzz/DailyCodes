#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
4
AlbertEinstein 1328
GeorgeWalkerBush 860
LiuMengmeng 1475
BillGates 1328
*/

struct student
{
	char name[30];
	int score;
};

int cmp(const void *a,const void *b )
{
	return strcmp((*(struct student *)a).name,(*(struct student *)b).name);
}

int cmpsc(const void *a,const void *b )
{
	return (*(struct student *)b).score - (*(struct student *)a).score;
}

int main()
{
	struct student info[105];
	int t;
	scanf("%d",&t);
	
	for(int i=0;i<t;i++)
	{
		scanf("%s %d",info[i].name,&info[i].score);
	}
	
	qsort(info,t,sizeof(info[0]),cmpsc);
	
	for(int i=0;i<t-1;i++)
	{
		if(info[i].score == info[i+1].score)
		{
			qsort(&info[i],2,sizeof(info[0]),cmp);
		}
	}
	
	for(int i=0;i<t;i++)
	{
		printf("Name:%s\ntotal:%d\n\n",info[i].name,info[i].score);
	}
	
	return 0;
}

