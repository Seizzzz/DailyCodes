#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[100];
    gets(a);
    
    int fenshu[11]={25,18,15,12,10,8,6,4,2,1};
    
    int len=strlen(a);
    
    int fen=0;
    
    for(int i=0;i<len;i++)
    {
            if(a[i]=='1') fen+=fenshu[0];
            else if(a[i]=='2') fen+=fenshu[1];
            else if(a[i]=='3') fen+=fenshu[2];
            else if(a[i]=='4') fen+=fenshu[3];
            else if(a[i]=='5') fen+=fenshu[4];
            else if(a[i]=='6') fen+=fenshu[5];
            else if(a[i]=='7') fen+=fenshu[6];
            else if(a[i]=='8') fen+=fenshu[7];
            else if(a[i]=='9') fen+=fenshu[8];
            else if(a[i]=='0') fen+=fenshu[9];
    }
    
    printf("%d\n",fen);

    return 0;
}

