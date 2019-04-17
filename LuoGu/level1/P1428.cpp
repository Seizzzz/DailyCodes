#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int love[n];
	for(int i=1;i<=n;i++) scanf("%d",&love[i]);
	
	for(int fish=1;fish<=n;fish++)
	{
		int count=0;
		for(int j=1;j<=fish;j++)
		{
			if(love[j]<love[fish]) count++;
		}
		printf("%d ",count);
	}
	
	return 0;
}
