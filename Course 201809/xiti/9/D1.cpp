#include <stdio.h>

int a[1000005];

int cal(int* a,int len)
{
	if(len==1) return a[0];
	else
	{
		int sum=0;
		for(int i=0;i<len;i++) sum+=a[i];
		
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	
	while(t--)
	{
		
		char temp='\0';
		int i=0;
		for(;;i++)
		{
			if((temp=getchar())!='\n')
			{
				a[i]=temp-'0';
			}
			else break;
		}
		
		printf("%d\n",cal(a,i-1));
	}

	return 0;
}

