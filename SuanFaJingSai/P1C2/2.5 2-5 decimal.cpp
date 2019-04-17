#include <stdio.h>
#include <math.h>

int main()
{
    const int INF = 1e6;
    int a,b,c,kase = 0;
    int num[105];
    while(scanf("%d %d %d",&a,&b,&c) == 3 && a && a <= INF && b <= INF && c <= 100 ) {
        if(a > b)   //num[0] 存放小数点左边部分
        {
            num[0] = a/b;
        }
        else if(a < b)
        {
            num[0] = 0;
        }
        else
        {
            printf("1.");
            for(int i = 1;i <= c;i++)
                printf("0");
            printf("\n");
            continue;
        }


        for(int i = 1;i <= c;i++)
        {
            a = a%b*10;
            num[i] = a/b;
        }

        printf("Case %d: %d.",++kase,num[0]);
        for(int i = 1;i <= c;i++)
            printf("%d",num[i]);
        printf("\n");

    }
}
