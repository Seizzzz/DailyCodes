#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
	int* c= (int*)a;
	int* d= (int*)b;
	return c[1] - d[1];
}

int main()
{
	int n,s,a,b,cnt=0;
	scanf("%d%d%d%d",&n,&s,&a,&b);
	
	int maxheight=a+b;
	
	int data[n+2][2];
	
	for(int i=0;i<n;i++) scanf("%d%d",&data[i][0],&data[i][1]);
	
	qsort(data[0],n,sizeof(data[0]),cmp);
	
	for(int i=0;i<n;i++)
	{
		if(s>=0)
		{
			if(maxheight>=data[i][0])  //高度足够 
			{
				if(s-data[i][1]>=0)   //力气足够 
				{
					cnt++;
					s-=data[i][1];
				}
			}
			else continue; 
		}
		else break;
	}
	
	printf("%d\n",cnt);
	
	return 0;
}
