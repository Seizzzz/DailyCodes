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
	cout << "100���ռ�¼�������\n" << endl;
	return;
}

void InputData()
{
	struct Product temp;

	cout << "��������Ʒ��Ϣ[IDΪ-1�����������]��"; 
	cout << "��ƷID:";	cin >> temp.ID;
	cout << "��Ʒ����";	cin >> temp.Name;
	cout << "������";	cin >> temp.Quantity;
	cout << "�۸�";	cin >> temp.Price;		cout << endl;
	
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
			cout << "�������н������ټ���" << endl;
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
		cout << "����������ѡ��\n"
			 << "1--����һ��100���ռ�¼���ļ�\n"
			 << "2--������Ʒ��¼\n"
			 << "3--������Ʒ��¼\n"
			 << "4--ɾ����Ʒ��¼\n"
			 << "5--���ȫ����Ʒ��¼\n"
			 << "6--�˳�����" << endl;
		cin >> StatusValue;
		Status(StatusValue);
	}
	
	iofile.close();
	return 0;
}

