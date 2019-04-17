#include <stdio.h>
#include <string.h>

int main()
{
	char a[500],c;
	int cnt[30]={0};
	
	//获取输入 
	int cntn=0,point=0;
	while(cntn<4)
	{
		if((c=getchar())!='\n')
		{
			a[point]=c;
			point++;
		}
		else cntn++;
	}
	
	//统计内容 
	int str = strlen(a);
	for(int i=0;i<str;i++)
	{
		if(a[i]!=' ')
		{
			cnt[a[i]-'A'+1]++;
		}
	}
	//for(int i=1;i<=26;i++) printf("%d",cnt[i]);
	
	//最大值 
	int max=-1;
	for(int i=1;i<=26;i++)
	{
		if(cnt[i]>max) max=cnt[i];
	}
	//printf("%d",max);
	
	//逐行输出
	for(int i=max;i>0;i--)
	{
		for(int j=1;j<=26;j++)
		{
			if(cnt[j]-i>=0) printf("* ");
			else printf("  ");
		}
		printf("\n");
	} 
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");

	return 0;
}

