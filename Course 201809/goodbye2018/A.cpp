#include <stdio.h>
#include <string.h>

int judge(char* ip,int len)
{
	int cntdot=0;
	for(int i=0;i<len;i++)
	{
		if((ip[i] >= '0' && ip[i]<='9') || ip[i]=='.')
		{
			if(ip[i]=='.') cntdot++;
		}
		else return 0;
	}
	
	if(cntdot==3);
	else return 0;
	
	int a,b,c,d;
	
	int start=0,end;
	for(;ip[end]!='.';end++)
	{
		if(end-start>3) return 0;
	}
	
	if(end-start==1) a=ip[start]-'0';
	else if(end-start==2) a=(ip[start]-'0')*10 + ip[start+1]-'0';
	else if(end-start==3) a=(ip[start]-'0')*100 + (ip[start+1]-'0')*10 +ip[start+2]-'0';
	
	start=end+1;
	end++;
	for(;ip[end]!='.';end++)
	{
		if(end-start>3) return 0;
	}
	
	if(end-start==1) b=ip[start]-'0';
	else if(end-start==2) b=(ip[start]-'0')*10 + ip[start+1]-'0';
	else if(end-start==3) b=(ip[start]-'0')*100 + (ip[start+1]-'0')*10 +ip[start+2]-'0';
	
	start=end+1;
	end++;
	for(;ip[end]!='.';end++)
	{
		if(end-start>3) return 0;
	}
	
	if(end-start==1) c=ip[start]-'0';
	else if(end-start==2) c=(ip[start]-'0')*10 + ip[start+1]-'0';
	else if(end-start==3) c=(ip[start]-'0')*100 + (ip[start+1]-'0')*10 +ip[start+2]-'0';
	start=end+1;
	end++;
	for(;end<len;end++)
	{
		if(end-start>3) return 0;
	}
	
	if(end-start==1) d=ip[start]-'0';
	else if(end-start==2) d=(ip[start]-'0')*10 + ip[start+1]-'0';
	else if(end-start==3) d=(ip[start]-'0')*100 + (ip[start+1]-'0')*10 +ip[start+2]-'0';
	
	if(a>=0 && a<=255);
	else return 0;
	if(b>=0 && b<=255);
	else return 0;
	if(c>=0 && c<=255);
	else return 0;
	if(d>=0 && d<=255);
	else return 0;
	
	return 1;
	
	
} 

int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	
	while(t--)
	{
		char ip[20];
		gets(ip);
		int len=strlen(ip);
		if(judge(ip,len)==1) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}

