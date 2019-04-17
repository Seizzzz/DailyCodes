#include <stdio.h>

/*
2
34052419800101001X
310105199412049278
*/

int main()
{
	int t,m;
	scanf("%d",&t);
	int a[25];
	
	char zuihou;
	int c[]={1,0,'X',9,8,7,6,5,4,3,2};
	
	while(t--)
	{
		for(int i=0;i<17;i++) scanf("%1d",&a[i]);
		zuihou=getchar();
		int sum=0;
		sum= sum + 7*a[0] + 9*a[1] + 10*a[2] +5*a[3]+8*a[4]+4*a[5]+2*a[6]+a[7]+6*a[8]+3*a[9]+7*a[10]+9*a[11]+10*a[12]+5*a[13]+8*a[14]+4*a[15]+2*a[16];
		m=sum%11;
		
		if(m==2)
		{
			if(zuihou=='X') printf("right\n");
			else printf("wrong\n");
		}
		else if(c[m]==zuihou-'0') printf("right\n");
		else printf("wrong\n");
	}
	
	
	

	return 0;
}

