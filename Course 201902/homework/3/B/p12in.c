#include <stdio.h>
 
int main()
{
   FILE *fp = NULL; //delete this
   
   fp = fopen("/tmp/test.txt", "w+");/* what
   */
   fprintf(fp, "This is testing for fprintf...\n");/*
   this please
   */
   fprintf(fp, "This is testing for fprintf...\n");/**/
   this please
   */
   */
   */
   */
   fputs("This is testing for fputs...\n", fp);/*
   fclose(fp);*/ok;
}


#include <bits/stdc++.h>
#define maxn 105 //默认行最大元素个数 
using namespace std;

FILE* inptr=fopen("p12in.c","r"); //输入文件指针 只读 
FILE* outptr=fopen("p12out.c","w"); //输出文件指针 只写 

int main()
{
	char nowline[maxn]; //用于存储当前行 
	bool isomiting=false; //标记遇到/*且未遇到*/ 即正在省略的状态 
	
	while(fgets(nowline,maxn,inptr)) //EOF前每次读取一行 
	{
		bool special=false; //定义有注释标记的为特殊行  
		int nowlinelen=strlen(nowline); //取当前行长度 
		
		if(isomiting) //若此前有/*且未遇到*/ 则优先在此行查找*/ 
		{
			for(int i=0;i<nowlinelen-1;i++) //循环查找*/ 
			{
				if(nowline[i]=='*' && nowline[i+1]=='/')
				{
					/*
					若此行后续仍有/* 应将该种情况改为递归判断并输出内容 
					但考虑到正常代码风格
					且不同IDE对该情况下的判断并不统一
					例如 "\* *\ *\" 
					其中*\配对的顺序判断不同 
					因此此处不做该判断而是直接输出后续整行 
					*/
					isomiting=false; //若遇到*/ 更改省略状态为否
					fprintf(outptr,"%s",nowline+i+2);
					fprintf(outptr,"\n"); //输出后续整行并换行 
					break; //跳出for循环 下接while的continue 
				}
			}
			continue; //读入下一行 
		}
		
		for(int i=0;i<nowlinelen-1;i++)
		{
			if(nowline[i]=='/')
			{
				if(nowline[i+1]=='/') //遇到 "//"
				{
					special=true; //标记该行为特殊行 
					nowline[i]='\0';
					fprintf(outptr,"%s",nowline); //输出"//"前内容 
					break;
				}
				else if(nowline[i+1]=='*') //遇到"/*" 
				{
					special=true; //标记该行为特殊行 
					nowline[i]='\0';
					fprintf(outptr,"%s",nowline);
					isomiting=true;
					for(int k=i+1;k<nowlinelen-1;k++) //寻找改行后是否有*/ 并继续输出*/后内容 
					{
						if(nowline[k]=='*' && nowline[k+1]=='/')
						{
							isomiting=false;
							fprintf(outptr,"%s",nowline+k+2);
							break;
						}
					}
					break;
				}
			}
		}
		
		if(!special) //若改行非特殊行 即无注释符号 直接输出该行内容 
		{
			fprintf(outptr,"%s",nowline);
		}
	}
	
	
	return 0;
}
