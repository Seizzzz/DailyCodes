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
	cout << "100���ռ�¼�������\n" << endl;
	return;
}

void InputData()
{
	while(true)
	{
		struct Product temp;
		cout << "��������Ʒ��Ϣ[IDΪ-1�����������]��"; 
		cout << "��ƷID:";	cin >> temp.ID;
		if(temp.ID==-1) break;
		cout << "��Ʒ����";	cin >> temp.Name;
		cout << "������";	cin >> temp.Quantity;
		cout << "�۸�";	cin >> temp.Price;		cout << endl;
		
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

	return 0;
}

