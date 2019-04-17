#include <bits/stdc++.h>
#define maxn 35
using namespace std;

ifstream infile("commodity.dat",ios::binary);
ofstream outfile("commodity.dat",ios::binary);

struct Product
{
	int ID;
	char Name[maxn];
	int Quantity;
	int Price;
};
int ProductSize=sizeof(struct Product);

//ifstream infile("commodity.dat");
//ofstream outfile("commodity.dat");

void CreateFile()
{
	for(int i=1;i<=100;i++)
	{
		struct Product temp;
		temp.ID=i;
		temp.Quantity=-1;
		outfile.write((char*)&temp,sizeof(struct Product)); 
	}
	outfile.close();
	cout << "100条空记录创建完毕\n" << endl;
	return;
}

void InputData()
{
	while(true)
	{
		struct Product temp;
		cout << "请输入商品信息[ID为-1代表输入结束]："; 
		cout << "商品ID:";	cin >> temp.ID;
		if(temp.ID==-1) break;
		cout << "商品名：";	cin >> temp.Name;
		cout << "数量：";	cin >> temp.Quantity;
		cout << "价格：";	cin >> temp.Price;		cout << endl;
		
		outfile.seekp((temp.ID-1)*sizeof(struct Product),ios::beg);
		outfile.write((char*)&temp,sizeof(struct Product));
	}
	outfile.close();
	return;
}

void UpdateData()
{
	
}

void DeleteData()
{
	
}

void OutputFile()
{
	for(int i=1;i<=100;i++)
	{
		struct Product temp;
		infile.seekg((i-1)*sizeof(struct Product),ios::beg);
		infile.read((char*)&temp,sizeof(struct Product));
		cout << temp.ID << " " << temp.Name << " " << temp.Price << " " << temp.Quantity << endl;
	}
	infile.close();
	return;
}

void Status(int Value)
{
	switch(Value){
		case 1:{
			CreateFile();
			break;
		}
		case 2:{
			InputData();
			break;
		}
		case 3:{
			UpdateData();
			break;
		}
		case 4:{
			DeleteData();
			break;
		}
		case 5:{
			OutputFile();
			break;
		}
		default:{
			cout << "程序运行结束，再见！" << endl;
			exit(0);
			break;
		}
	}
}

int main()
{
	int StatusValue=0;
	while(true)
	{
		cout << "请输入您的选择：\n"
			 << "1--创建一个100条空记录的文件\n"
			 << "2--输入商品记录\n"
			 << "3--更新商品记录\n"
			 << "4--删除商品记录\n"
			 << "5--输出全部商品记录\n"
			 << "6--退出程序" << endl;
		cin >> StatusValue;
		Status(StatusValue);
	}

	return 0;
}

