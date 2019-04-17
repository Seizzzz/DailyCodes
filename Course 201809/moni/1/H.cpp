#include <stdio.h>

int main()
{
    char a[8][8];
    for(int i=0;i<8;i++) scanf("%s",&a[i]);
    
    int m,n;
    scanf("%d %d",&m,&n);
    getchar();
    char temp='\0';
    
    int flag=0;
    while((temp=getchar())!='\n')
    {
    	if(flag==0)
    	{
    		printf("%c",a[m][n]);
    		flag++;
		}
    	switch(temp)
    	{
    		case '1':{
    			m=m-1;
          		n=n-2;
				break;
			}
			case '2':{
				m=m-2;
         		 n=n-1;
				break;
			}
			case '3':{
				m=m-2;
         		n=n+1;
				break;
			}
			case '4':{
				m=m-1;
         		n=n+2;
				break;
			}
			case '5':{
				m=m+1;
         		n=n+2;
				break;
			}
			case '6':{
				m=m+2;
        		n=n+1;
				break;
			}
			case '7':{
				m=m+2;
        		n=n-1;
				break;
			}
			case '8':{
				m=m+1;
    			n=n-2;
				break;
			}
		}
		printf("%c",a[m][n]);
	}
	
	printf("\n");
	return 0;
}

