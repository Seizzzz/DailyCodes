#include <stdio.h>
#include <stdlib.h> 

struct team
{
	char name[23];
	int zong;
	int shi;
	int jifen;
}team[4];

int comp(void* p1,const void* p2)
{
	p1=*(struct team*)p1; 
	p2=*(struct team*)p2; 
	
	
	if(p1.jifen > p2.jifen) return 0;
	else if(p1.jifen < p2.jifen) return 1;
	else //p1.jifen == p2.jifen
	{
		if(p1.zong - p1.shi > p2.zong - p2.shi) return 0;
		else if(p1.zong - p1.shi < p2.zong - p2.shi) return 1;
		else
		{
			if(p1.zong > p2.zong) return 0;
			else if(p1.zong < p2.zong) return 1;
		}
	}
	return 0;
}


int main()
{
	
	scanf("%s",team[0].name);
	scanf("%d",&team[0].zong);
	scanf("%d",&team[0].shi);
	scanf("%d",&team[0].jifen);
	scanf("%s",team[1].name);
	scanf("%d",&team[1].zong);
	scanf("%d",&team[1].shi);
	scanf("%d",&team[1].jifen);
	scanf("%s",team[2].name);
	scanf("%d",&team[2].zong);
	scanf("%d",&team[2].shi);
	scanf("%d",&team[2].jifen);
	scanf("%s",team[3].name);
	scanf("%d",&team[3].zong);
	scanf("%d",&team[3].shi);
	scanf("%d",&team[3].jifen);
	
	
	qsort(team[0],4,sizeof(team[0]),comp);
	
	printf("%s\n",team[0].name);
	printf("%s\n",team[1].name);
	printf("%s\n",team[2].name);
	printf("%s\n",team[3].name);
	
	
	
	
	return 0;
}

