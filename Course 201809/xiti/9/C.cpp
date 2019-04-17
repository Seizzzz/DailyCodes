#include <stdio.h>
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
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) a[j][i]=u++;
	char temp;
	
	while((temp=getchar())=='i')
	{
		int n;
		scanf("nput %d:",&n);
		getchar();
		getchar();
		int x,y;
		scanf("%d%d",&x,&y);
		getchar();
		
		printf("output %d:",n);
		while((temp=getchar())!='\n')
		{
			printf("%d",a[x][y]);
			switch(temp-'0')
			{
				case 1:{
					x=x-1;
					y=y+1;
					break;
				}
				case 2:{
					y=y+1;
					break;
				}
				case 3:{
					x=x+1;
					y=y+1;
					break;
				}
				case 4:{
					x=x-1;
					break;
				}
				case 6:{
					x=x+1;
					break;
				}
				case 7:{
					x=x-1;
					y=y-1;
					break;
				}
				case 8:{
					y=y-1;
					break;
				}
				case 9:{
					x=x+1;
					y=y-1;
					break;
				}
			}
		}
		printf("%d",a[x][y]);
		getchar();

	}
	
	//for(int i=0;i<3;i++) for(int j=0;j<3;j++) printf("%d",a[i][j]);

	return 0;
}

