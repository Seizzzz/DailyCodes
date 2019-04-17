#include <stdio.h>
#include <stdlib.h>

/*
11 10
50  50  50  50  50  50  50  50  50  50
99  99  50  99  99  50  50  99  99  99
99  99  50  99  99  50  50  99  99  99
99  99  50  99  99  50  50  99  99  99
99  99  50  99  99  50  50  99  99  99
99  99  50  99  99  50  50  99  99  99
99  99  50  99  99  50  50  99  99  99
99  99  50  99  99  50  50  99  99  99
50  50  50  50  50  50  50  50  50  50
99  99  50  99  99  50  50  99  99  99
99  99  50  99  99  50  50  99  99  99
*/
int** a;

int cal(int* a,int i,int j)
{
	int flag=0;
}

int main()
{
	int m,n;
    scanf("%d%d",&m,&n);
    
    a=(int**)malloc((m+2)*sizeof(int*));
    for(int i=0;i<n;i++) a[i]=(int*)malloc((n+2)*sizeof(int));
    
    
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) a[i][j]=a[i][j]<50? 1:0;
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) printf("%d ",a[i][j]);
        printf("\n");
    }
    
    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		
		}
	}
	
	//printf("%d %d %d\n",maxhang,maxlie,(maxhang+1)*(maxlie+1));

    
    
    
    
    return 0;
}

