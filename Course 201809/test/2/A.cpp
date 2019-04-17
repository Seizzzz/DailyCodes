#include <stdio.h>

int main()
{
    int renshu,tishu;
    scanf("%d%d",&renshu,&tishu);
    
    int sy=tishu-renshu;
    
    int t2=0,t3=0,t4=0;
    for(int i=0;i<=sy;i++)
    {
            for(int j=0;j<=sy;j++)
            {
                    for(int k=0;k<=sy;k++)
                    {
                            if(i*1+j*2+k*3==sy) printf("%d %d %d\n",i,j,k);
                            }
                            }
                            }

    return 0;
} 
