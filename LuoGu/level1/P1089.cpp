#include <stdio.h>
#include <string.h>

int main()
{
	int cost[12],money,deposit=0,count=1;
	memset(cost,0,sizeof(cost));
	
	while(cost[12]==0)
	{
		scanf("%d",&cost[count]);
		count++;
	}
	
	for(int month=1;month<=12;month++)
	{
		money+=300;
		money-=cost[month];
		if(money<0)
		{
			printf("-%d",month);
			break;
		}
		else
		{
			if(month<12)
			{
			deposit+=(money-(money%100));
			money=money%100;
			
			}
			printf("deposit:%d money:%d\n",deposit,money);
		}
		
		if(month==12)
		{
			printf("%f",deposit*1.2+money);
		}
	}
	
}
