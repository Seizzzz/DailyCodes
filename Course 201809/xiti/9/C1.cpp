#include <stdio.h>
#include <string.h>
/*
input 1:
0 0
661166

input 2:
2 0
66772938
*/
int main()
{
	int a[3][3];
	int u=1;
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) a[i][j]=u++;
	int n,temp;
	
	while(scanf("input %d:",&n)==1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		getchar();
		
		char qisile[12];
		gets(qisile);
		int len=strlen(qisile);
		
		printf("output %d:",n);
		for(int i=0;i<len;i++)
		{
			//printf(" x=%d y=%d\n",x,y);
			printf("%d",a[x][y]);
			switch(qisile[i]-'0')
			{
				case 1:{
					y=y-1;
					x=x+1;
					break;
				}
				case 2:{
					x=x+1;
					break;
				}
				case 3:{
					y=y+1;
					x=x+1;
					break;
				}
				case 4:{
					y=y-1;
					break;
				}
				case 6:{
					y=y+1;
					break;
				}
				case 7:{
					y=y-1;
					x=x-1;
					break;
				}
				case 8:{
					x=x-1;
					break;
				}
				case 9:{
					y=y+1;
					x=x-1;
					break;
				}
			}
		}
		printf("%d\n",a[x][y]);
		getchar();

	}
	
	//for(int i=0;i<3;i++) for(int j=0;j<3;j++) printf("%d",a[i][j]);

	return 0;
}

