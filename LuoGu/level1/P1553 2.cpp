
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
 
    for(i=0;i<len;i++)//��¼С�����������ٷ������ŵ�λ��  
        if(number[i]=='.'||number[i]=='/'||number[i]=='%') 
        {
            flag=i;  
            for(j=len-1;number[j]=='0'&&number[j-1]!='.'&&number[j-1]!='/'&&number[j]!='%';j--)
    		len--;
        }
 
    for(i=0;i<flag;i++)//����ǰ
        result[i]=number[flag-i-1];  
    
    result[flag]=number[flag];  
    
    for(i=flag+1;i<len;i++)//���ź�
        result[i]=number[len-i+flag];  
    
 
    for(i=0;result[i]!='\0';i++)
    {
        if(flag==len)//�����ת����
        {
            if(len==1)	cout<<result[i]<<endl;
            else
            {
                for(j=0;result[j]=='0';j++)//�ų���λ��0		
                    if(result[j]!='0')			
                        break;		
 
                for(;result[j]!='\0';j++)//���
                    cout<<result[j];
                cout<<endl;
                break;
            }			
        }
        else//С�����������ٷ�����
        {
            for(j=0;result[j]=='0'&&j<flag&&result[j+1]!='/'&&result[j+1]!='%'&&result[j+1]!='.';j++)//���Է���λ
            if(result[j]!='0')//�ų���λ��0	
                break;		
            for(;j<flag;j++)//�������λǰ����
                cout<<result[j];
                   
 
            if(result[flag]=='.')//���С��
            {
                if((strlen(result)-flag)!=2)
                    for(k=strlen(result);result[k-1]=='0';k--)
                        result[k-1]='\0';
                for(;result[j]=='0'&&j>flag;j++)//�ų���λ��0
                    if(result[j]!='0')
                        break;
                for(;result[j]!='\0';j++)//�������λ��
                    cout<<result[j];
                cout<<endl;
                break;
            }
            if(result[flag]=='/')//����ٷ���
            {
                for(j++;result[j]=='0'&&j>flag;j++)//�ų���λ��0�����
                    if(result[j]!='0')
                        break;
                cout<<result[flag];//�������
                for(;result[j]!='\0';j++)//�������λ��
                    cout<<result[j];
                cout<<endl;
                break;
            }
            if(result[flag]=='%')//�������
            {
                for(j++;result[j]=='0'&&j>flag;j++)//�ų���λ��0�����
                    if(result[j]!='0')
                        break;
                cout<<result[flag];//�������
                for(;result[j]!='\0';j++)//�������λ��
                    cout<<result[j];
                cout<<endl;
                break;
            }
        }
    }
 
    return 0;  
}
