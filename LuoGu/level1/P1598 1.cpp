#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;


char a[110];
int num[27];
int main()
{
	int n,len,mmax=-100;
	for(int i=0;i<4;i++)
	{
		gets(a);
		len=strlen(a);
		for(int j=0;j<len;j++)
		{
			if(a[j]>='A'&&a[j]<='Z')
			{
				num[a[j]-'A']++;
			}
		}
	}
	
	for(int i=0;i<26;i++)
	{
		mmax=max(mmax,num[i]);
	}
	
	for(int i=mmax;i>0;i--)
	{
		for(int j=0;j<26;j++)
		{
			if(num[j]<i) 
			{
				cout<<' '<<' ';
				continue;
			}
			else if(num[j]>=i) 
			{
				cout<<'*'<<' ';
				continue;
			}
		}
		
		cout<<endl;
	}
	for(int i=0;i<26;i++)
	{
		printf("%c ",i+'A');
	}
	
	return 0;
}
