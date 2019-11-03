#include <bits/stdc++.h>
using namespace std;

struct term
{
	double c; //ϵ�� 
	int e; //ָ�� 
};

list<term> Multi_Polyn(list<term> a, list<term> b)
{
	list<term> ans; //��Ŵ𰸶���ʽ 
	ans.push_back(term{0, 0}); //��ʼԪ�� 
	
	while(!a.empty()) //������ʽa�д��ڴ���Ԫ�� 
	{
		list<term>::iterator ptr_ans=ans.begin(); //���ڲ�ѭ����� �Ż�ɨ����� 
		 
		for(list<term>::iterator ptr_b = b.begin();;++ptr_b)
		{
			term tmp; //��ʱ��ż����� 
			tmp.c = (*ptr_b).c * a.front().c; //ϵ����� 
			tmp.e = (*ptr_b).e + a.front().e; //ָ����� 
			
			for(/*list<term>::iterator ptr_ans=ans.begin();*/;; ++ptr_ans) //�ɽ������� ֻ����ϴ�ֹͣ��λ�ü���ɨ�� �ʽ�ptr_ans��� 
			{
				if((*ptr_ans).e == tmp.e) //ans�����и�ָ���µ�ϵ�� ����� 
				{
					(*ptr_ans).c += tmp.c;
					break;
				}
				else if((*ptr_ans).e < tmp.e) //ansͬ���������� ��ʱ���ж�δ�и�ָ���µ�ϵ�� ��insert 
				{
					ans.insert(ptr_ans,tmp);
					break;
				}
			}
			if(ptr_b == --b.end()) break; //�ж�b����ʽ�����Ƿ��Ѿ��˱�
			--ptr_ans; //�ָ������ж϶��ƶ���ans  
		}
		a.pop_front(); //pop�Ѽ�����ϵ�a�� 
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

