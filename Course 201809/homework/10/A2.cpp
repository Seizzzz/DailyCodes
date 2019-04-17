#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,a,b,j;
    float c,d[4][5]={0},e;
    i=1;j=0;e=0;
    scanf("%d",&n);
    while(i<=n)
    {
        scanf("%d%d%f",&a,&b,&c);
        d[a-1][b-1]=d[a-1][b-1]+c;
        i=i+1;
    }
    i=0;
    while(i<=4)
    {
        while(j<=3)
        {
            printf("%.1f\t",d[j][i]);
            e=e+d[j][i];
            j=j+1;
        }
        printf("%.1f\n",e);
        i=i+1;
        j=0;
        e=0;
    }
    j=0;e=0;
    while(j<=3)
    {
        e=e+d[j][0]+d[j][1]+d[j][2]+d[j][3]+d[j][4];
        printf("%.1f\t",d[j][0]+d[j][1]+d[j][2]+d[j][3]+d[j][4]);
        j=j+1;
    }
    printf("%.1f\n",e);
    return 0;
}

