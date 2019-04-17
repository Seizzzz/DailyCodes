#include <bits/stdc++.h>

//题目定义的常量 
#define MaxProduct 100		//最大商品数量 
#define MaxNameLength 35	//最大商品名长度 

FILE* fp=fopen("commodity.dat","rb+"); //文件输入输出指针 

struct Product
{
	int ID;						//记录号（商品ID） 
	char Name[MaxNameLength];	//商品名
	int Quantity;				//数量
	double Price;				//价格 
};
int ProductSize=sizeof(struct Product); //记录结构体大小 

void CreateFile() //创建100条空记录文件 
{
	for(int i=1;i<=MaxProduct;i++) //循环依次对100条记录进行编号 
	{
		struct Product temp; //临时变量用于存储输入信息 
		temp.ID=i;
		temp.Quantity=-1; //标记数量为-1时 该商品不存在 后续将沿用此判断 
		fseek(fp,(i-1)*ProductSize,0);
		fwrite(&temp,ProductSize,1,fp);
	}
	printf("%d条空记录创建完毕\n\n",MaxProduct);
	return;
}

void OutputFile(bool single) //输出商品信息 通过bool值实现输出单条或全部记录 
{
	if(single) //当single为true 只输出当前fp指针后的一条记录 方便后续输出 
	{
		struct Product temp;
		printf("原商品信息如下：\n");
		fread(&temp,ProductSize,1,fp); //读取当前指针后的一条记录 
		printf("记录号（商品ID）商品名\t数量\t价格\n");
		printf("%d\t\t%s\t%d\t%.2lf\n",temp.ID,temp.Name,temp.Quantity,temp.Price);
	}
	else //当single为false 从头输出全部的商品信息 
	{
		printf("商品信息如下：\n");
		printf("记录号（商品ID）商品名\t数量\t价格\n");
		for(int i=1;i<=MaxProduct;i++) //循环读取一条记录 
		{
			struct Product temp; //临时变量用于存储输入信息 
			fseek(fp,(i-1)*ProductSize,0);
			fread(&temp,ProductSize,1,fp);
			if(temp.Quantity==-1) continue; //当该商品不存在时 跳过 
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
		struct Product temp; //临时变量用于存储输入信息 
		printf("请输入商品信息[ID为-1代表输入结束]：\n");
		printf("商品ID:");	scanf("%d",&temp.ID);
		if(temp.ID==-1) break; //当输入-1时 跳出循环 
		printf("商品名：");	scanf("%s",temp.Name);
		printf("数量：");	scanf("%d",&temp.Quantity);
		printf("价格：");	scanf("%lf",&temp.Price);
		
		fseek(fp,(temp.ID-1)*ProductSize,0);
		fwrite(&temp,ProductSize,1,fp); //将临时变量写入文件中 
	}
	printf("商品信息输入结束\n");
	OutputFile(false); //输入结束时 输出全部的商品信息 
	
	return;
}

void UpdateData()
{
	while(true)
	{
		struct Product oldinfo,newinfo; //oldinfo用于记录当前存在的商品信息 newinfo用于临时存储输入的信息 
		
		printf("请输入待更新商品ID[ID为-1代表结束更新]\n"); scanf("%d",&oldinfo.ID); getchar();
		if(oldinfo.ID==-1) break; //当输入-1时 跳出循环 
		newinfo.ID=oldinfo.ID; //oldinfo和newinfo的ID相同 
		
		fseek(fp,(oldinfo.ID-1)*ProductSize,0);
		fread(&oldinfo,ProductSize,1,fp); //读入原本存在的商品信息 
		
		if(oldinfo.Quantity==-1) printf("对不起，记录号为%d的商品不存在，无法更新\n",oldinfo.ID); //沿用商品数量为-1时该商品不存在的判断 
		else
		{
			fseek(fp,(oldinfo.ID-1)*ProductSize,0);
			OutputFile(true); //输入前输出当前存在的信息 
			char temp; 
			printf("请输入更新信息[如某项不更新请直接按回车键]：\n");
			/*
			此处对于回车键的判断若使用getchar()逐个读取、判断、拼接、传回则过于繁琐
			代码也将因此晦涩难懂 
			才疏学浅，自认为C并不能很好的实现这样的功能 
			又因为此处有三种类型的变量 书写起来实在不美观且低效
			此处借用了cin.unget() 将已读入的字符放回缓冲区 
			*/
			printf("商品名：");
			std::cin.get(temp); //读取一个字符 判断是否为换行符 
			if(temp=='\n') strcpy(newinfo.Name,oldinfo.Name); //若缺省 复制oldinfo.Name 
			else
			{
				std::cin.unget(); //读到的不是空格 则退回 
				std::cin >> newinfo.Name; //流输入 
				std::cin.get(); //吸收换行符 并保持流输入的连贯性 
			}
			
			printf("数量："); //同上
			std::cin.get(temp);
			if(temp=='\n') newinfo.Quantity=oldinfo.Quantity;
			else
			{
				std::cin.unget();
				std::cin >> newinfo.Quantity;
				std::cin.get();
			}
			
			printf("价格："); //同上 
			std::cin.get(temp);
			if(temp=='\n') newinfo.Price=oldinfo.Price;
			else
			{
				std::cin.unget();
				std::cin >> newinfo.Price;
				std::cin.get();
			}
			
			printf("更新后商品信息如下：\n");
			printf("记录号（商品ID）商品名\t数量\t价格\n");
			printf("%d\t\t%s\t%d\t%.2lf\n",newinfo.ID,newinfo.Name,newinfo.Quantity,newinfo.Price); //展示读入并覆盖的新商品信息 
		}
		
	}
	
	printf("更新工作结束\n\n");
	return;
}

void DeleteData()
{
	while(true)
	{
		struct Product temp; //存储待删除的商品信息 
		printf("请输入待删除商品ID[记录号为-1代表结束删除]:\n"); scanf("%d",&temp.ID); getchar();
		if(temp.ID==-1) break; //当输入-1时 跳出循环 
		
		fseek(fp,(temp.ID-1)*ProductSize,0);
		fread(&temp,ProductSize,1,fp); //读入待删除的商品信息 
		if(temp.Quantity==-1) //沿用商品数量为-1时该商品不存在的判断 
		{
			printf("对不起，记录号为%d的商品不存在，无法进行删除操作\n",temp.ID);
			continue; //读入下一件商品 
		}
		
		//下接 若该商品存在 
		fseek(fp,(temp.ID-1)*ProductSize,0);
		OutputFile(true); //输出待删除的商品信息  
		
		char judge; //读入Y/N 确认删除操作 
		bool judged=false; //若读入非Y/N 则将继续循环询问是否确认 
		while(!judged)
		{
			printf("是否确实删除（确认按Y，取消按N)？\n");
			scanf("%c",&judge); //读入确认符号 
			
			if(judge=='Y')
			{
				temp.Quantity=-1;
				fseek(fp,(temp.ID-1)*ProductSize,0);
				fwrite(&temp,ProductSize,1,fp);
				printf("记录号为%d的商品成功删除\n",temp.ID);
			}
			else if(judge=='N') printf("您选择不删除记录号为%d的商品\n",temp.ID);
			else continue; //重新循环询问 
			judged=true; //上接Y/N 将judged置为已判断 
		}
		OutputFile(false); //输出全部的商品信息 
	}
	
	printf("删除工作结束\n\n");
	return;
}

inline void Status(int Value) //跳转入不同的子程序 缩减main函数 
{
	switch(Value){ //Value用于记录main中的传入值 并由此跳转不同子函数进行操作 
		case 1:{
			CreateFile(); //创建指定数量空记录的文件
			break;
		}
		case 2:{
			InputData(); //输入商品记录
			break;
		}
		case 3:{
			UpdateData(); //更新商品记录
			break;
		}
		case 4:{
			DeleteData(); //删除商品记录 
			break;
		}
		case 5:{
			OutputFile(false); //输出全部商品记录
			break;
		}
		case 6:{ 
			printf("程序运行结束，再见！\n"); 
			exit(0); //直接退出程序
		}
		default:{ //若非已定义的操作 则回到main重新询问 
			return;
		}
	}
}

int main()
{
	int StatusValue=0;
	while(true) //循环询问操作 程序只能由Status子函数结束 
	{
		printf("请输入您的选择：\n");
		printf("1--创建一个%d条空记录的文件\n",MaxProduct);
		printf("2--输入商品记录\n");
		printf("3--更新商品记录\n");
		printf("4--删除商品记录\n");
		printf("5--输出全部商品记录\n");
		printf("6--退出程序\n");
		
		scanf("%d",&StatusValue);
		Status(StatusValue); //判断并调用不同的函数 
	}
	return 0;
}

