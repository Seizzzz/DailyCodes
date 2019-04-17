
#include<iostream>  
#include<cstring>  
using namespace std;  
int main()  
{  
    char number[25]={'\0'},result[25]={'\0'};
    int i,j,k;
    int len,flag; 
 
    cin>>number;
                   
 
    len=strlen(number);  
    flag=len;
 
    for(i=0;i<len;i++)//记录小数、分数、百分数符号的位置  
        if(number[i]=='.'||number[i]=='/'||number[i]=='%') 
        {
            flag=i;  
            for(j=len-1;number[j]=='0'&&number[j-1]!='.'&&number[j-1]!='/'&&number[j]!='%';j--)
    		len--;
        }
 
    for(i=0;i<flag;i++)//符号前
        result[i]=number[flag-i-1];  
    
    result[flag]=number[flag];  
    
    for(i=flag+1;i<len;i++)//符号后
        result[i]=number[len-i+flag];  
    
 
    for(i=0;result[i]!='\0';i++)
    {
        if(flag==len)//输出反转整数
        {
            if(len==1)	cout<<result[i]<<endl;
            else
            {
                for(j=0;result[j]=='0';j++)//排除首位是0		
                    if(result[j]!='0')			
                        break;		
 
                for(;result[j]!='\0';j++)//输出
                    cout<<result[j];
                cout<<endl;
                break;
            }			
        }
        else//小数、分数、百分数和
        {
            for(j=0;result[j]=='0'&&j<flag&&result[j+1]!='/'&&result[j+1]!='%'&&result[j+1]!='.';j++)//忽略符号位
            if(result[j]!='0')//排除首位是0	
                break;		
            for(;j<flag;j++)//输出符号位前的数
                cout<<result[j];
                   
 
            if(result[flag]=='.')//输出小数
            {
                if((strlen(result)-flag)!=2)
                    for(k=strlen(result);result[k-1]=='0';k--)
                        result[k-1]='\0';
                for(;result[j]=='0'&&j>flag;j++)//排除首位是0
                    if(result[j]!='0')
                        break;
                for(;result[j]!='\0';j++)//输出符号位后
                    cout<<result[j];
                cout<<endl;
                break;
            }
            if(result[flag]=='/')//输出百分数
            {
                for(j++;result[j]=='0'&&j>flag;j++)//排除首位是0的情况
                    if(result[j]!='0')
                        break;
                cout<<result[flag];//输出符号
                for(;result[j]!='\0';j++)//输出符号位后
                    cout<<result[j];
                cout<<endl;
                break;
            }
            if(result[flag]=='%')//输出分数
            {
                for(j++;result[j]=='0'&&j>flag;j++)//排除首位是0的情况
                    if(result[j]!='0')
                        break;
                cout<<result[flag];//输出符号
                for(;result[j]!='\0';j++)//输出符号位后
                    cout<<result[j];
                cout<<endl;
                break;
            }
        }
    }
 
    return 0;  
}
