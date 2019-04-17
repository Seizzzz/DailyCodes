#include <bits/stdc++.h>
using namespace std;

fstream iofile("data.txt");

struct Product
{
	int ID;
	string Name;
	int Quantity;
	int Price;
};

void CreateFile()
{
	for(int i=1;i<=100;i++) iofile << i << "\t" << "NULL\t" << "-1\t" << "-1\n";
	cout << "100条空记录创建完毕\n" << endl;
	return;
}

void InputData()
{
	struct Product temp;

	cout << "请输入商品信息[ID为-1代表输入结束]："; 
	cout << "商品ID:";	cin >> temp.ID;
	cout << "商品名：";	cin >> temp.Name;
	cout << "数量：";	cin >> temp.Quantity;
	cout << "价格：";	cin >> temp.Price;		cout << endl;
	
	iofile.seekg(temp.ID);
	iofile.seekp(temp.ID);
	
	iofile << "20";
	
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
	
	iofile.close();
	return 0;
}

