//ֻ����˻���Ҫ�� 
#include <bits/stdc++.h>
#define maxn 105 //Ĭ�������Ԫ�ظ��� 
using namespace std;

FILE* inptr=fopen("p12in.c","r"); //�����ļ�ָ�� ֻ�� 
FILE* outptr=fopen("p12out.c","w"); //����ļ�ָ�� ֻд 

int main()
{
	char nowline[maxn]; //���ڴ洢��ǰ�� 
	bool isomiting=false; //�������/*��δ����*/ ������ʡ�Ե�״̬ 
	
	while(fgets(nowline,maxn,inptr)) //EOFǰÿ�ζ�ȡһ�� 
	{
		bool special=false; //������ע�ͱ�ǵ�Ϊ������  
		int nowlinelen=strlen(nowline); //ȡ��ǰ�г��� 
		
		if(isomiting) //����ǰ��/*��δ����*/ �������ڴ��в���*/ 
		{
			for(int i=0;i<nowlinelen-1;i++) //ѭ������*/ 
			{
				if(nowline[i]=='*' && nowline[i+1]=='/')
				{
					/*
					�����к�������\* Ӧ�����������Ϊ�ݹ�(ջ?)�жϲ�������� 
					�����ǵ�����������
					�Ҳ�ͬIDE�Ը�����µ��жϲ���ͳһ
					���� "\* *\ *\" 
					����*\��Ե�˳���жϲ�ͬ 
					��˴˴��������ж϶���ֱ������������� 
					*/
					isomiting=false; //������*/ ����ʡ��״̬Ϊ��
					fprintf(outptr,"%s",nowline+i+2);
					fprintf(outptr,"\n"); //����������в����� 
					break; //����forѭ�� �½�while��continue 
				}
			}
			continue; //������һ�� 
		}
		
		for(int i=0;i<nowlinelen-1;i++)
		{
			if(nowline[i]=='/')
			{
				if(nowline[i+1]=='/') //���� "//"
				{
					special=true; //��Ǹ���Ϊ������ 
					nowline[i]='\0';
					fprintf(outptr,"%s",nowline); //���"//"ǰ���� 
					break;
				}
				else if(nowline[i+1]=='*') //����"/*" 
				{
					special=true; //��Ǹ���Ϊ������ 
					nowline[i]='\0';
					fprintf(outptr,"%s",nowline);
					isomiting=true;
					for(int k=i+1;k<nowlinelen-1;k++) //Ѱ�Ҹ��к��Ƿ���*/ ���������*/������ 
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
		
		if(!special) fprintf(outptr,"%s",nowline); //�����з������� ����ע�ͷ��� ֱ������������� 
	}
	
	
	return 0;
}

