#include <stdio.h>
#include <string.h>

void reverse1(char* a,int len)
{
	char* end=a+len-2;
	char* start;
	for(int cs=0;cs<4;cs++)
	{
		for(start = end;*(start) != ' ' && start != a-1;start--);
		{
			for(char* i=start+1;i<=end;i++) printf("%c",*i);
			printf(" ");
		}
		end=start-1;
	}
	printf("\n");
}

void reverse2(char* a,int len)
{
	char* start=a;
	char* end;
	for(int cs=0;cs<4;cs++)
	{
		for(end=start;*(end) != ' ';end++);
		{
			for(char* i=end-1;i>=start;i--) printf("%c",*i);
			printf(" ");
		}
		start=end+1;
	}
	printf("\n");
}

void reverse3(char* a,int len)
{
	for(int i=len-2;i>=0;i--) printf("%c",a[i]);
	printf("\n");
}

int main()
{
	char a[10005],temp[10005];
	for(int i=0;i<4;i++)
	{
		gets(temp);
		strcat(a,temp);
		strcat(a," ");
	}
	
	int len=strlen(a);
	
	reverse1(a,len);
	reverse2(a,len);
	reverse3(a,len);

	return 0;
}

