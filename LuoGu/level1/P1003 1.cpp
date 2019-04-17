#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int dt[n+2][5];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<4;j++)
			scanf("%d",&dt[i][j]);
			
	int xf,yf;
	scanf("%d%d",&xf,&yf);
	
	
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(xf>=dt[i][0] && xf<=dt[i][0]+dt[i][2])
		{
			if(yf>=dt[i][1] && yf<=dt[i][1]+dt[i][3])
			{
				ans++;
			}
		}
	}
	
	if(ans==0) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}

