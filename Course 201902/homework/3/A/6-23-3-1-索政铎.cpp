#include <bits/stdc++.h>
#define INF 0x7fffffff //定义行最大元素个数 若超出此范围 即超出int的计数范围 行最小元素个数的统计会出现问题 
using namespace std;

ifstream infile("p1.txt"); //文件输入流 

int capital=0,lowercase=0,digit=0,others=0; //记录大写字母、小写字母、数字、其他元素个数 
int CntLine=0,MaxLen=0,MinLen=INF; 			//记录行数、行最大元素个数、行最小元素个数 
int CntCapital[26],CntLowercase[26];		//桶记录元素出现次数 

void OutputResult()
{
	cout << "The result is:" << endl;
	
	cout << "Task1:\n" //任务1 输出各种类型char个数 
		 << "capital:" << capital << "\n"
		 << "lowercase:" << lowercase << "\n"
		 << "digit:" << digit << "\n"
		 << "others:" << others << "\n" << endl;
	
	cout << "Task2:\n" //任务2 输出全局变量中所记录的行数、行最大元素个数、行最小元素个数 
		 << "line:" << CntLine << "\n"
		 << MaxLen << " characters in max line.\n"
		 << MinLen << " characters in min line." << "\n" << endl;
	
		cout << "Task3:\n" //任务3 输出元素出现次数 
			 << "CAPITAL:" << "\n";
		for(int i=0;i<26;i++)
		{
			cout << (char)(i+'A') << ":" << CntCapital[i] << "\t"; //强制类型转换输出每种元素的名称 
			if((i+1)%4==0) cout << "\n"; //每输出四个换行 
		}
		cout << "\n";
		cout << "LOWERCASE:" << "\n";
		for(int i=0;i<26;i++)
		{
			cout << (char)(i+'a') << ":" << CntLowercase[i] << "\t"; //强制类型转换输出每种元素的名称 
			if((i+1)%4==0) cout << "\n"; //每输出四个换行 
		}
		cout << endl;
	
	return;
}

int main()
{
	std::ios::sync_with_stdio(false); //取消流与stdio的同步 加快输入输出速度 
	
	for(int i=0;i<26;i++) CntCapital[i]=CntLowercase[i]=0; //初始化桶计数为0 
	//initialized
	
	string NowLine; //记录行 
	while(infile >> NowLine) //按流输入行 
	{
		int NowLen=NowLine.length(); //记录当前行元素个数 
		for(int i=0;i<NowLen;i++) //遍历行中元素 
		{
			if(isupper(NowLine[i])) //大写字母 
			{
				capital++;
				CntCapital[NowLine[i]-'A']++;
			}
			else if(islower(NowLine[i])) //小写字母 
			{
				lowercase++;
				CntLowercase[NowLine[i]-'a']++;
			}
			else if(isdigit(NowLine[i])) digit++; //数字 
			else others++; //其他符号 
		}
		
		
		if(NowLen>MaxLen) MaxLen=NowLen; //更新行最大元素个数
		if(NowLen<MinLen) MinLen=NowLen; //更新行最小元素个数
		CntLine++; //更新行数 
	}
	
	OutputResult(); //输出答案 

	return 0;
}

