#include <stdio.h>

void get(int* cnt,int n)
{
	cnt[n/100]++;
	cnt[(n/10)%10]++;
	cnt[n%10]++;
	return;
}

int main()
{
	int a,b,c,ans=0;
	scanf("%d%d%d",&a,&b,&c);
	
	for(int i=100;(i/a)*c<=999;i++)
	{
		int cnt[12]={0};
		
		int n1=i,n2=(i/a)*b,n3=(i/a)*c;
		if(i%a==0) //printf("%d %d %d\n",i,(i/a)*b,(i/a)*c);
		{
			get(cnt,n1);
			get(cnt,n2);
			get(cnt,n3);
		}
		for(int i=1;i<=9;i++)
		{
			if(cnt[i]!=1) break;
			if(i==9)
			{
				printf("%d %d %d\n",n1,n2,n3);
				ans++;
			}
		}
	}
	
	if(ans==0) printf("No!!!\n");
	
	
	return 0;
}
