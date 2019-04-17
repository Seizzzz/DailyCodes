#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int t=n;
	int a[n+2]={0};
	
	while(n--)
	{
		int t;
		scanf("%d",&t);
		a[t]++;
	}
	
	int big=-1;
	int choice;
	
	for(int person=1;person<=t;person++)
	{
		if(a[person]>big)
		{
			big=a[person];
			choice=person;
		}
	}
	
	printf("%d\n",choice);

	return 0;
}

