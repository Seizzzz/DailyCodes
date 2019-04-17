#include <stdio.h>

int getDays(int y,int m)
{
	if(m==2)
	{
		if(y%400==0) printf("There are 29 days in month 2 year %d.\n",y);
		else if(y%4==0 && y%100!=0) printf("There are 29 days in month 2 year %d.\n",y);
		else printf("There are 28 days in month 2 year %d.",y);
	}
	else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) printf("There are 31 days in month %d year %d.\n",m,y);
	else printf("There are 30 days in month %d year %d.\n",m,y);
}


int main()
{
	int y,m;
	scanf("%d%d",&y,&m);
	getDays(y,m);
	
	return 0;
}
