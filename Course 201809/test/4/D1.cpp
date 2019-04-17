#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    
    int a[m][n];
    
    for(int i=0;i<m;i++)
    {
            for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    }
    
    int flag=0;
    int hang=0,lie=0;
    
    int maxhang=0,maxlie=0;
    
    for(int j=0;j<n;j++)
    {
    	hang=0;
    	flag=0;
    	for(int i=0;i<m;i++)
    	{
            if(flag==0 && a[j][i]>50)
            {
                hang++;
                flag=1;
            }
            if(a[j][i]<=50) flag=0;
   		}
    	if(hang>maxhang) maxhang=hang;
	}
    
    //printf("%d ",hang);
    
    flag=0;
    
    for(int j=0;j<m;j++)
    {
		lie=0;
		flag=0;
    	for(int i=0;i<n;i++)
    	{
        	if(flag==0 && a[i][j]>50)
        	{
        	    lie++;
    		    flag=1;
    		}
    		if(a[i][j]<=50) flag=0;
   		}
    	if(lie>maxlie) maxlie=lie;
	}
    
    //printf("%d",lie);
    if(maxhang==0 || maxlie==0)
    {
               printf("0\n");
               return 0;
    }
    printf("%d\n",maxhang*maxlie);


    //system("pause");
    return 0;
}

