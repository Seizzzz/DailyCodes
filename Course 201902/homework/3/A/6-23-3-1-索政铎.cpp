#include <bits/stdc++.h>
#define INF 0x7fffffff //���������Ԫ�ظ��� �������˷�Χ ������int�ļ�����Χ ����СԪ�ظ�����ͳ�ƻ�������� 
using namespace std;

ifstream infile("p1.txt"); //�ļ������� 

int capital=0,lowercase=0,digit=0,others=0; //��¼��д��ĸ��Сд��ĸ�����֡�����Ԫ�ظ��� 
int CntLine=0,MaxLen=0,MinLen=INF; 			//��¼�����������Ԫ�ظ���������СԪ�ظ��� 
int CntCapital[26],CntLowercase[26];		//Ͱ��¼Ԫ�س��ִ��� 

void OutputResult()
{
	cout << "The result is:" << endl;
	
	cout << "Task1:\n" //����1 �����������char���� 
		 << "capital:" << capital << "\n"
		 << "lowercase:" << lowercase << "\n"
		 << "digit:" << digit << "\n"
		 << "others:" << others << "\n" << endl;
	
	cout << "Task2:\n" //����2 ���ȫ�ֱ���������¼�������������Ԫ�ظ���������СԪ�ظ��� 
		 << "line:" << CntLine << "\n"
		 << MaxLen << " characters in max line.\n"
		 << MinLen << " characters in min line." << "\n" << endl;
	
		cout << "Task3:\n" //����3 ���Ԫ�س��ִ��� 
			 << "CAPITAL:" << "\n";
		for(int i=0;i<26;i++)
		{
			cout << (char)(i+'A') << ":" << CntCapital[i] << "\t"; //ǿ������ת�����ÿ��Ԫ�ص����� 
			if((i+1)%4==0) cout << "\n"; //ÿ����ĸ����� 
		}
		cout << "\n";
		cout << "LOWERCASE:" << "\n";
		for(int i=0;i<26;i++)
		{
			cout << (char)(i+'a') << ":" << CntLowercase[i] << "\t"; //ǿ������ת�����ÿ��Ԫ�ص����� 
			if((i+1)%4==0) cout << "\n"; //ÿ����ĸ����� 
		}
		cout << endl;
	
	return;
}

int main()
{
	std::ios::sync_with_stdio(false); //ȡ������stdio��ͬ�� �ӿ���������ٶ� 
	
	for(int i=0;i<26;i++) CntCapital[i]=CntLowercase[i]=0; //��ʼ��Ͱ����Ϊ0 
	//initialized
	
	string NowLine; //��¼�� 
	while(infile >> NowLine) //���������� 
	{
		int NowLen=NowLine.length(); //��¼��ǰ��Ԫ�ظ��� 
		for(int i=0;i<NowLen;i++) //��������Ԫ�� 
		{
			if(isupper(NowLine[i])) //��д��ĸ 
			{
				capital++;
				CntCapital[NowLine[i]-'A']++;
			}
			else if(islower(NowLine[i])) //Сд��ĸ 
			{
				lowercase++;
				CntLowercase[NowLine[i]-'a']++;
			}
			else if(isdigit(NowLine[i])) digit++; //���� 
			else others++; //�������� 
		}
		
		
		if(NowLen>MaxLen) MaxLen=NowLen; //���������Ԫ�ظ���
		if(NowLen<MinLen) MinLen=NowLen; //��������СԪ�ظ���
		CntLine++; //�������� 
	}
	
	OutputResult(); //����� 

	return 0;
}

