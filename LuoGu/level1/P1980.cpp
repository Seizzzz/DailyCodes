#include <stdio.h>

int main()
{
    int n,x;
    scanf("%d %d",&n,&x);
    int cnt=0;
    for(;n>0;n--){
        int y=n;
        while(y){
        	if(y%10==x) cnt++;
        	y/=10;
        }
        }
        printf("%d\n",cnt);
     return 0;
}
