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
	
	while(!a.empty()) //当多项式a中存在待乘元素 
	{
		list<term>::iterator ptr_ans=ans.begin(); //由内层循环提出 优化扫描次数 
		 
		for(list<term>::iterator ptr_b = b.begin();;++ptr_b)
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
			if(ptr_b == --b.end()) break; //判断b多项式中项是否已经乘毕
			--ptr_ans; //恢复用于判断而移动的ans  
		}
		a.pop_front(); //pop已计算完毕的a项 
	}
	if(ans.back().c == 0) ans.pop_back();
	return ans;
}


int main()
{
	std::ios::sync_with_stdio(false);
	
	list<term> polya;
	list<term> polyb;
	
	int n1,n2;
	cin >> n1;
	while(n1--)
	{
		term tmp;
		cin >> tmp.e >> tmp.c;
		polya.push_back(tmp);
	}
	cin >> n2;
	while(n2--)
	{
		term tmp;
		cin >> tmp.e >> tmp.c;
		polyb.push_back(tmp);
	}
	
	list<term> ans = Multi_Polyn(polya,polyb);
	
	cout << ans.size();
	for(list<term>::iterator ptr=ans.begin();ptr!=ans.end();ptr++) cout << " " << (*ptr).e << " " << setprecision(1) << fixed << (*ptr).c;
	cout << endl;

	return 0;
}

