#include <stdio.h>
 
int main()
{
   FILE *fp = NULL;    
   fp = fopen("/tmp/test.txt", "w+");

   fprintf(fp, "This is testing for fprintf...\n");

   fprintf(fp, "This is testing for fprintf...\n");
   this please
   */
   */
   */
   */
   fputs("This is testing for fputs...\n", fp);ok;

}


#include <bits/stdc++.h>
#define maxn 105 using namespace std;

FILE* inptr=fopen("p12in.c","r"); FILE* outptr=fopen("p12out.c","w"); 
int main()
{
	char nowline[maxn]; 	bool isomiting=false; 	
	while(fgets(nowline,maxn,inptr)) 	{
		bool special=false; 		int nowlinelen=strlen(nowline); 		
		if(isomiting) 		{
			for(int i=0;i<nowlinelen-1;i++) 			{
				if(nowline[i]=='*' && nowline[i+1]=='/')
				{
					

					isomiting=false; 					fprintf(outptr,"%s",nowline+i+2);
					fprintf(outptr,"\n"); 					break; 				}
			}
			continue; 		}
		
		for(int i=0;i<nowlinelen-1;i++)
		{
			if(nowline[i]=='/')
			{
				if(nowline[i+1]=='/') 				{
					special=true; 					nowline[i]='\0';
					fprintf(outptr,"%s",nowline); 					break;
				}
				else if(nowline[i+1]=='*') 				{
					special=true; 					nowline[i]='\0';
					fprintf(outptr,"%s",nowline);
					isomiting=true;
					for(int k=i+1;k<nowlinelen-1;k++) 					{
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
		
		if(!special) 		{
			fprintf(outptr,"%s",nowline);
		}
	}
	
	
	return 0;
}
