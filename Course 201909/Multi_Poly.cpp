#include <bits/stdc++.h>
using namespace std;

struct term
{
	double c; //系数 
	int e; //指数 
};

list<term> Multi_Polyn(list<term> a, list<term> b)
{
	list<term> ans; //存放答案多项式 
	ans.push_back(term{0, 0}); //初始元素 
	
	while(a.size() > 1) //当多项式a中存在待乘元素 
	{
		list<term>::iterator ptr_ans=ans.begin(); //由内层循环提出 优化扫描次数 
		 
		for(list<term>::iterator ptr_b = b.begin();;)
		{
			term tmp; //临时存放计算结果 
			tmp.c = (*ptr_b).c * a.front().c; //系数相乘 
			tmp.e = (*ptr_b).e + a.front().e; //指数相加 
			
			for(/*list<term>::iterator ptr_ans=ans.begin();*/;; ++ptr_ans) //由降次排列 只需从上次停止的位置继续扫描 故将ptr_ans提出 
			{
				if((*ptr_ans).e == tmp.e) //ans中已有该指数下的系数 则相加 
				{
					(*ptr_ans).c += tmp.c;
					break;
				}
				else if((*ptr_ans).e < tmp.e) //ans同样降次排列 此时可判断未有该指数下的系数 则insert 
				{
					ans.insert(ptr_ans,tmp);
					break;
				}
			}
			if(++ptr_b == --b.end()) break; //判断b多项式中项是否已经乘毕
			--ptr_ans; //恢复用于判断而移动的ans  
		}
		a.pop_front(); //pop已计算完毕的a项 
	}
	return ans;
}


int main()
{
	std::ios::sync_with_stdio(false);
	
	list<term> polya;
	list<term> polyb;
	
	string line;
	stringstream ss_line1,ss_line2;
	getline(cin,line);
	ss_line1 << line;
	while(ss_line1)
	{
		term tmp;
		ss_line1 >> tmp.c >> tmp.e;
		polya.push_back(tmp);
	}
	getline(cin,line);
	ss_line2 << line;
	while(ss_line2)
	{
		term tmp;
		ss_line2 >> tmp.c >> tmp.e;
		polyb.push_back(tmp);
	}
	
	list<term> ans = Multi_Polyn(polya,polyb);
	
	for(list<term>::iterator ptr=ans.begin();ptr!=ans.end();ptr++) cout << (*ptr).c << " " << (*ptr).e << endl;

	return 0;
}

