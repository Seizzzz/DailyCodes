#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/*
4
Where there is hope ,there is a way.
Welcome Beijing.
Nice idea.
Have fun.
*/

int cmp(const void *a,const void *b )
{
	return strcmp((char*)b,(char*)a);
}

int main()
{
	int t;
	char temp[100005];
	scanf("%d",&t);
	getchar();
	
	char** a=(char**)malloc(sizeof(char*)*t);

	for(int i=0;i<t;i++)
	{
		memset(temp,0,sizeof(temp));
		char c='\0';
		
		for(int j=0;c!='\n';j++)
		{
			c=getchar();
			temp[j]=c;
			temp[j+1]='\0';
		}
		
		int strlentemp=strlen(temp); 
		
		a[i]=(char*)malloc(sizeof(char*) * strlentemp);
		
		//strcpy(temp,a[i]);
		for(int j=0;j<strlentemp;j++) a[i][j]=temp[j];
		
		a[i][strlentemp]='\0';
	}
	
	qsort(a[0],t,sizeof(a[0]),cmp);
	
	//for(int i=0;i<t;i++) printf("%s\n",a[i]);
	
	for(int i=t-1;i>=0;i--)
	{
		int len=strlen(a[i]);
		for(int j=0;j<len;j++) printf("%c",a[i][j]);
		//printf("\n");
	}
	
	
	
	/*
	int cntn=0,cnt=0;
	char temp;
	for(int i=0;cntn<=4;i++)
	{
		str[i]=(temp=getchar());
		if(temp=='\n') cntn++;
		cnt++;
	}
	*/
        
	//qsort(s,100,sizeof(s[0]),cmp);

	return 0;
}

