#include <stdio.h>
#include <stdlib.h>

struct inf
{
       char name[30];
       char duiname[30];
       int fen;
}book[23];

int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
            scanf("%s",book[i].name);
            scanf("%s",book[i].duiname);
            scanf("%d",&book[i].fen);
    }
    
    for(int j=n;j>0;j--)
    {
            for(int i=0;i<n-1;i++)
    {
            if(book[i].fen > book[i+1].fen);
            else
            {
                struct inf a;
                a=book[i];
                book[i]=book[i+1];
                book[i+1]=a;
            }
    }
}
    
    for(int i=0;i<n;i++)
    {
            printf("%s ",book[i].name);
            printf("%s ",book[i].duiname);
            printf("%d\n",book[i].fen);
    }

    return 0;
}

