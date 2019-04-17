#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    
    int** a=(int**)malloc(sizeof(int*) * (n+2));
    
    for(int i=0;i<n;i++)
    {
            int temp;
            scanf("%d",&temp);
            a[i]=(int*)malloc((temp+2) * sizeof(int));
            a[i][0]=temp;
            for(int j=1;j<=a[i][0];j++) scanf("%d",&a[i][j]);
    }
    
    int pingjun[n];
    for(int i=0;i<n;i++)
    {
            pingjun[i]=0;
            for(int j=1;j<=a[i][0];j++) pingjun[i]+=a[i][j];
            pingjun[i] =pingjun[i] / a[i][0];
    }
    
    int vis[n];
    memset(vis,0,sizeof(vis));
    
    
    int min=999,wei=0;
    for(int cishu=0;cishu<n;cishu++)
    {
            min=999;
            int i;
            for(i=0;i<n;i++)
            {
                    if(pingjun[i]<min && vis[i]==0)
                    {
                                      min=pingjun[i];
                                       wei=i;           
                    }
            }
            vis[wei]=1;
            for(int j=1;j<=a[wei][0];j++) printf("%d ",a[wei][j]);
            printf("\n");
    }
    
    //system("pause");
    return 0;
}

