#include <stdio.h>

int main()
{
	int height[15],arm,count=0;
	
	for(int i=1;i<=10;i++) scanf("%d",&height[i]);
	scanf("%d",&arm);
	
	for(int i=1;i<=10;i++)
	{
		if(arm+30>=height[i]) count++;
	}
	printf("%d",count);
	
	return 0;
}
