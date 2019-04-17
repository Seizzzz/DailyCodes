#include <stdio.h>

char name[105][30];
int score[105];

void exchange(int i,int j)
{
	
}

int main()
{
	int t;
	scanf("%d",&t);
	
	int a=0;
	while(a<t)
	{
		getchar();
		char temp='\0';
		for(int i=0;temp!=' ';i++)
		{
			temp=getchar();
			name[a][i]=temp;
		}
		scanf("%d",&score[a]);
	}

	return 0;
}

