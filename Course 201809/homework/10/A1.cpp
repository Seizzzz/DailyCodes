#include<stdio.h>
#include<math.h>

/*
4
1 1 35.6
1 2 23.1
1 1 89.3
4 5 22.6
*/
int main()
{
    int n,i=1,a,b,j=0;
    float c,d[4][5]={0},e=0;
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
    	float sum=d[j][0]+d[j][1]+d[j][2]+d[j][3]+d[j][4];
        e=e+sum;
        printf("%.1f\t",sum);
        j=j+1;
    }
    printf("%.1f\n",e);
    
    return 0;
}

