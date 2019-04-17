#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define maxn 1005

int cal1(char* equation,int st,int ed)
{
	int len=ed-st,sum=0,temp=len;
	for(;len>=0;len--)
	{
		sum+= (equation[st+len]-'0') * (int)pow(10,temp-len);
	}
	
	return sum;
}

int cal(char* equation,int st,int ed,int flag1,int flag2)
{
	if(flag1==0 && flag2==0) return cal1(equation,st,ed);
	else if(flag1==0 && flag2==1) return -cal1(equation,st,ed);
	else if(flag1==1 && flag2==0) return -cal1(equation,st,ed);
	else return cal1(equation,st,ed);
}

int main()
{
	char equation[maxn];
	
	char temp;
	temp=getchar();
	if(temp=='-')
	{
		equation[0]=temp;
		gets(equation+1);
	}
	else
	{
		equation[0]='+';
		equation[1]=temp;
		gets(equation+2);
	}
	
	int len=strlen(equation);
	
	equation[len]='+';
	equation[len+1]='\0';
	
	int symbol[maxn];
	memset(symbol,0,sizeof(symbol));
	
	int pnt=0;
	int atequal;
	
	for(int i=0;i<=len;i++)
	{
		if(equation[i]=='=') atequal=i;
		if(equation[i]!='+' && equation[i]!='-' && equation[i]!='=') continue;
		else
		{
			symbol[pnt]=i;
			pnt++;
		}
	}
	
	int special=0,common=0;
	
	int rec=0,pnt1=-1,pnt2=-1;

	symbol[pnt]=len+1;
	symbol[pnt+1]='\0';
	
	for(;pnt1<=len;)
	{
		pnt1=symbol[rec];
		pnt2=symbol[rec+1];
		if(pnt1==len) break;
		
		if(pnt2==pnt1+1)
		{
			rec++;
			continue;
		}
		
		for(;pnt2<=len;)
		{
			int flag1,flag2; //flag1正负 flag2左右
			if(equation[pnt1]=='+' || equation[pnt1]=='=') flag1=0;
			else flag1=1;
			if(pnt1<atequal) flag2=0;
			else flag2=1;
			
			if(!isdigit(equation[pnt1+1]))
			{
				if(flag1==0 && flag2==0) special++;
				else if(flag1==0 && flag2==1) special--;
				else if(flag1==1 && flag2==0) special--;
				else special++;
				break;
			}
			
			int flag3=1; //flag3 常数 
			for(int point=pnt1+1;point<pnt2;point++)
			{
				if(isdigit(equation[point]));
				else
				{
					flag3=0;
					break;
				}
			}
			
			if(flag3) common+=cal(equation,pnt1+1,pnt2-1,flag1,flag2);
			else special+=cal(equation,pnt1+1,pnt2-2,flag1,flag2);
			
			break;
		}
		rec++;
	}
	
	for(int i=0;i<len;i++)
	{
		if(isdigit(equation[i]) || equation[i]=='+' || equation[i]=='-' || equation[i]=='=');
		else
		{
			printf("%c=",equation[i]);
			break;
		}
	}
	
	printf("%.3f\n",-(float)common/special);
	
	
	return 0;
}

