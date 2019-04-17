#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char a[100];
    gets(a);
    
    int isfu=0;
    if(a[0]=='A') isfu=1;
    
    int isw=0;
    int len=strlen(a);
    if(a[len-1]=='W') isw=1;
    
    if(isw==1)
    {
              int shu=0;
              int ge=(int)pow(10,(isfu? len-3:len-2));
              for(int i=(isfu)? 1:0;i<len-1;i++)
              {
                      shu+=(10-a[i]+'A')*ge;
                      ge/=10;
              }
              //if(isfu==1 && (shu+23173)/11>0) printf("-");
              if(isfu==1) shu=0-shu;
              printf("%d",(shu+23173)/11);
           printf("M\n")  ;
    }
    else
    {
         
              int shu=0;
              int ge=(int)pow(10,(isfu? len-3:len-2));
              for(int i=(isfu)? 1:0;i<len-1;i++)
              {
                      shu+=(10-a[i]+'A')*ge;
                      ge/=10;
              }
              //printf("%d ",shu);
              //if(isfu==1 && shu*11-23173>0) printf("-");
              if(isfu==1) shu=0-shu;
              printf("%d",shu*11-23173);
              printf("W\n")  ;
    }

    return 0;
}

