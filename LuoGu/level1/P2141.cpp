#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int num[n+5];
	int record[n+5];
	
	memset(record,0,sizeof(record));
	
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	
	int count=0;
	for(int test=1;test<=n;test++)
	{
		
		for(int i=1;i<=n;i++)
		{
			
			if(i==test) continue;
			for(int j=1;j<=i;j++)
			{
				if(i==j || j==test) continue;
				else if(num[i]+num[j]==num[test])
				{
					if(record[test]==0) count++;
					record[test]++;
				}
			}	
		}
		
	}
	printf("%d\n",count);
	
	return 0;
}
