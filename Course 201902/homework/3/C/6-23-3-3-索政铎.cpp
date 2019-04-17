#include <bits/stdc++.h>

//��Ŀ����ĳ��� 
#define MaxProduct 100		//�����Ʒ���� 
#define MaxNameLength 35	//�����Ʒ������ 

FILE* fp=fopen("commodity.dat","rb+"); //�ļ��������ָ�� 

struct Product
{
	int ID;						//��¼�ţ���ƷID�� 
	char Name[MaxNameLength];	//��Ʒ��
	int Quantity;				//����
	double Price;				//�۸� 
};
int ProductSize=sizeof(struct Product); //��¼�ṹ���С 

void CreateFile() //����100���ռ�¼�ļ� 
{
	for(int i=1;i<=MaxProduct;i++) //ѭ�����ζ�100����¼���б�� 
	{
		struct Product temp; //��ʱ�������ڴ洢������Ϣ 
		temp.ID=i;
		temp.Quantity=-1; //�������Ϊ-1ʱ ����Ʒ������ ���������ô��ж� 
		fseek(fp,(i-1)*ProductSize,0);
		fwrite(&temp,ProductSize,1,fp);
	}
	printf("%d���ռ�¼�������\n\n",MaxProduct);
	return;
}

void OutputFile(bool single) //�����Ʒ��Ϣ ͨ��boolֵʵ�����������ȫ����¼ 
{
	if(single) //��singleΪtrue ֻ�����ǰfpָ����һ����¼ ���������� 
	{
		struct Product temp;
		printf("ԭ��Ʒ��Ϣ���£�\n");
		fread(&temp,ProductSize,1,fp); //��ȡ��ǰָ����һ����¼ 
		printf("��¼�ţ���ƷID����Ʒ��\t����\t�۸�\n");
		printf("%d\t\t%s\t%d\t%.2lf\n",temp.ID,temp.Name,temp.Quantity,temp.Price);
	}
	else //��singleΪfalse ��ͷ���ȫ������Ʒ��Ϣ 
	{
		printf("��Ʒ��Ϣ���£�\n");
		printf("��¼�ţ���ƷID����Ʒ��\t����\t�۸�\n");
		for(int i=1;i<=MaxProduct;i++) //ѭ����ȡһ����¼ 
		{
			struct Product temp; //��ʱ�������ڴ洢������Ϣ 
			fseek(fp,(i-1)*ProductSize,0);
			fread(&temp,ProductSize,1,fp);
			if(temp.Quantity==-1) continue; //������Ʒ������ʱ ���� 
			printf("%d\t\t%s\t%d\t%.2lf\n",temp.ID,temp.Name,temp.Quantity,temp.Price);
		}
		printf("\n");
	}
	return;
}

void InputData()
{
	while(true)
	{
		struct Product temp; //��ʱ�������ڴ洢������Ϣ 
		printf("��������Ʒ��Ϣ[IDΪ-1�����������]��\n");
		printf("��ƷID:");	scanf("%d",&temp.ID);
		if(temp.ID==-1) break; //������-1ʱ ����ѭ�� 
		printf("��Ʒ����");	scanf("%s",temp.Name);
		printf("������");	scanf("%d",&temp.Quantity);
		printf("�۸�");	scanf("%lf",&temp.Price);
		
		fseek(fp,(temp.ID-1)*ProductSize,0);
		fwrite(&temp,ProductSize,1,fp); //����ʱ����д���ļ��� 
	}
	printf("��Ʒ��Ϣ�������\n");
	OutputFile(false); //�������ʱ ���ȫ������Ʒ��Ϣ 
	
	return;
}

void UpdateData()
{
	while(true)
	{
		struct Product oldinfo,newinfo; //oldinfo���ڼ�¼��ǰ���ڵ���Ʒ��Ϣ newinfo������ʱ�洢�������Ϣ 
		
		printf("�������������ƷID[IDΪ-1�����������]\n"); scanf("%d",&oldinfo.ID); getchar();
		if(oldinfo.ID==-1) break; //������-1ʱ ����ѭ�� 
		newinfo.ID=oldinfo.ID; //oldinfo��newinfo��ID��ͬ 
		
		fseek(fp,(oldinfo.ID-1)*ProductSize,0);
		fread(&oldinfo,ProductSize,1,fp); //����ԭ�����ڵ���Ʒ��Ϣ 
		
		if(oldinfo.Quantity==-1) printf("�Բ��𣬼�¼��Ϊ%d����Ʒ�����ڣ��޷�����\n",oldinfo.ID); //������Ʒ����Ϊ-1ʱ����Ʒ�����ڵ��ж� 
		else
		{
			fseek(fp,(oldinfo.ID-1)*ProductSize,0);
			OutputFile(true); //����ǰ�����ǰ���ڵ���Ϣ 
			char temp; 
			printf("�����������Ϣ[��ĳ�������ֱ�Ӱ��س���]��\n");
			/*
			�˴����ڻس������ж���ʹ��getchar()�����ȡ���жϡ�ƴ�ӡ���������ڷ���
			����Ҳ����˻�ɬ�Ѷ� 
			����ѧǳ������ΪC�����ܺܺõ�ʵ�������Ĺ��� 
			����Ϊ�˴����������͵ı��� ��д����ʵ�ڲ������ҵ�Ч
			�˴�������cin.unget() ���Ѷ�����ַ��Żػ����� 
			*/
			printf("��Ʒ����");
			std::cin.get(temp); //��ȡһ���ַ� �ж��Ƿ�Ϊ���з� 
			if(temp=='\n') strcpy(newinfo.Name,oldinfo.Name); //��ȱʡ ����oldinfo.Name 
			else
			{
				std::cin.unget(); //�����Ĳ��ǿո� ���˻� 
				std::cin >> newinfo.Name; //������ 
				std::cin.get(); //���ջ��з� ������������������� 
			}
			
			printf("������"); //ͬ��
			std::cin.get(temp);
			if(temp=='\n') newinfo.Quantity=oldinfo.Quantity;
			else
			{
				std::cin.unget();
				std::cin >> newinfo.Quantity;
				std::cin.get();
			}
			
			printf("�۸�"); //ͬ�� 
			std::cin.get(temp);
			if(temp=='\n') newinfo.Price=oldinfo.Price;
			else
			{
				std::cin.unget();
				std::cin >> newinfo.Price;
				std::cin.get();
			}
			
			printf("���º���Ʒ��Ϣ���£�\n");
			printf("��¼�ţ���ƷID����Ʒ��\t����\t�۸�\n");
			printf("%d\t\t%s\t%d\t%.2lf\n",newinfo.ID,newinfo.Name,newinfo.Quantity,newinfo.Price); //չʾ���벢���ǵ�����Ʒ��Ϣ 
		}
		
	}
	
	printf("���¹�������\n\n");
	return;
}

void DeleteData()
{
	while(true)
	{
		struct Product temp; //�洢��ɾ������Ʒ��Ϣ 
		printf("�������ɾ����ƷID[��¼��Ϊ-1�������ɾ��]:\n"); scanf("%d",&temp.ID); getchar();
		if(temp.ID==-1) break; //������-1ʱ ����ѭ�� 
		
		fseek(fp,(temp.ID-1)*ProductSize,0);
		fread(&temp,ProductSize,1,fp); //�����ɾ������Ʒ��Ϣ 
		if(temp.Quantity==-1) //������Ʒ����Ϊ-1ʱ����Ʒ�����ڵ��ж� 
		{
			printf("�Բ��𣬼�¼��Ϊ%d����Ʒ�����ڣ��޷�����ɾ������\n",temp.ID);
			continue; //������һ����Ʒ 
		}
		
		//�½� ������Ʒ���� 
		fseek(fp,(temp.ID-1)*ProductSize,0);
		OutputFile(true); //�����ɾ������Ʒ��Ϣ  
		
		char judge; //����Y/N ȷ��ɾ������ 
		bool judged=false; //�������Y/N �򽫼���ѭ��ѯ���Ƿ�ȷ�� 
		while(!judged)
		{
			printf("�Ƿ�ȷʵɾ����ȷ�ϰ�Y��ȡ����N)��\n");
			scanf("%c",&judge); //����ȷ�Ϸ��� 
			
			if(judge=='Y')
			{
				temp.Quantity=-1;
				fseek(fp,(temp.ID-1)*ProductSize,0);
				fwrite(&temp,ProductSize,1,fp);
				printf("��¼��Ϊ%d����Ʒ�ɹ�ɾ��\n",temp.ID);
			}
			else if(judge=='N') printf("��ѡ��ɾ����¼��Ϊ%d����Ʒ\n",temp.ID);
			else continue; //����ѭ��ѯ�� 
			judged=true; //�Ͻ�Y/N ��judged��Ϊ���ж� 
		}
		OutputFile(false); //���ȫ������Ʒ��Ϣ 
	}
	
	printf("ɾ����������\n\n");
	return;
}

inline void Status(int Value) //��ת�벻ͬ���ӳ��� ����main���� 
{
	switch(Value){ //Value���ڼ�¼main�еĴ���ֵ ���ɴ���ת��ͬ�Ӻ������в��� 
		case 1:{
			CreateFile(); //����ָ�������ռ�¼���ļ�
			break;
		}
		case 2:{
			InputData(); //������Ʒ��¼
			break;
		}
		case 3:{
			UpdateData(); //������Ʒ��¼
			break;
		}
		case 4:{
			DeleteData(); //ɾ����Ʒ��¼ 
			break;
		}
		case 5:{
			OutputFile(false); //���ȫ����Ʒ��¼
			break;
		}
		case 6:{ 
			printf("�������н������ټ���\n"); 
			exit(0); //ֱ���˳�����
		}
		default:{ //�����Ѷ���Ĳ��� ��ص�main����ѯ�� 
			return;
		}
	}
}

int main()
{
	int StatusValue=0;
	while(true) //ѭ��ѯ�ʲ��� ����ֻ����Status�Ӻ������� 
	{
		printf("����������ѡ��\n");
		printf("1--����һ��%d���ռ�¼���ļ�\n",MaxProduct);
		printf("2--������Ʒ��¼\n");
		printf("3--������Ʒ��¼\n");
		printf("4--ɾ����Ʒ��¼\n");
		printf("5--���ȫ����Ʒ��¼\n");
		printf("6--�˳�����\n");
		
		scanf("%d",&StatusValue);
		Status(StatusValue); //�жϲ����ò�ͬ�ĺ��� 
	}
	return 0;
}

