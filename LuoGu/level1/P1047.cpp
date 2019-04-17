#include <stdio.h>
#include <string.h>

int main()
{
	int l,m,count=0;
	scanf("%d%d",&l,&m);
	int road[l+10];
	memset(road,0,sizeof(road));
	
	for(int i=1;i<=m;i++)
	{
		int m1,m2;
		scanf("%d%d",&m1,&m2);
		for(int j=m1;j<=m2;j++) road[j]=1;
	}
	
	for(int i=0;i<=l;i++)
	{
		if(road[i]==0) count++;
	}
	printf("%d",count);
	
	
	return 0;
}
