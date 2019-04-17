#include <stdio.h>
#include <string.h>

//最长子序列 didactical advantage
/*
advantage
didactical
advantage
*/


int main()
{
	char text1[20],text2[20];
	gets(text1+1);
	gets(text2+1);
	
	text1[0]='\n';
	text2[0]='\n';
	int lentext1=strlen(text1),lentext2=strlen(text2);
	
	int cal[lentext1+1][lentext2+1]={0,0};
	
	for(int i=0;i<lentext2;i++) cal[0][i]=0;
	
	
	for(int i=1;i<lentext1;i++)
	{
		for(int j=1;j<lentext2;j++)
		{
			if(text1[i] == text2[j])
			{
				cal[i][j]=cal[i-1][j-1]+1;
			}
			else
			{
				cal[i][j]=cal[i-1][j] > cal[i][j-1] ? cal[i-1][j] : cal[i][j-1];
			}
		}
	}
	
	for(int i=0;i<lentext1;i++)
	{
		for(int j=0;j<lentext2;j++)
		{
			printf("%d ",cal[i][j]);
		}
		printf("\n");
	}
	
	

	return 0;
}

