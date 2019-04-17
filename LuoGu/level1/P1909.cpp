#include <stdio.h>

int main()
{
	int s,a1,a2,a3,p1,p2,p3;
	scanf("%d%d%d%d%d%d%d",&s,&a1,&p1,&a2,&p2,&a3,&p3);
	int cost1=(s%a1==0)? (s/a1)*p1:(s/a1+1)*p1;
	int cost2=(s%a2==0)? (s/a2)*p2:(s/a2+1)*p2;
	int cost3=(s%a3==0)? (s/a3)*p3:(s/a3+1)*p3;
	
	printf("%d",(cost1<=cost2&&cost1<=cost3)? cost1:(cost2<=cost1&&cost2<=cost3)? cost2:cost3);
	
	return 0;
}
