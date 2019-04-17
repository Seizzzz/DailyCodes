#include <stdio.h>
#include <ctype.h>
int main()
{
	int a[20], i=0;
 	char ch;
	 while((ch=getchar())>='0'&&ch<='9')
  		a[i++]=ch-'0';
 	while(i>0&&a[--i]==0);
	 for(;i>=0;i--)
  		printf("%d",a[i]);
 	if(ch=='\n') return 0;
  	
 	printf("%c",ch);

 	if(ch=='%')
 	 	return 0;
 	i=0;
 	while((ch=getchar())>='0'&&ch<='9')
  		a[i++]=ch-'0';
 	int k=0;
 	while(k<i&&a[k++]==0);
 	while(i>0&&a[--i]==0);
 	for(;i>=k-1;i--)
 		 printf("%d",a[i]);
 		 
 	return 0; 
 } 

