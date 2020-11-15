#include "jump.h"

bool JumpMethod::equal(double a, double b)
{
	if (abs(a - b) < 1e-8) return true;
	return false;
}

double JumpMethod::sol()
{
	int left = 0, right = 0;
	first[number] = 1;

	for (int i = number; i > 0; --i)
	{
		int jumpoint = left;
		for (int j = left; j <= right; j++)
		{
			if (p[j]->w + weight[i] > capacity) break;
			double newWeight = p[j]->w + weight[i];
			double newValue = p[j]->v + value[i]; //q[i] = p[i] ⊕ (w(i-1), v(i-1))

			while (p[jumpoint]->w < newWeight && jumpoint <= right) //不是受控点 加入跳跃点
			{
				p.push_back(new node(p[jumpoint]->w, p[jumpoint]->v));
				++jumpoint;
			}
			
			if (equal(p[jumpoint]->w, newWeight) && jumpoint <= right) //受控
			{
				if (newValue < p[jumpoint]->v) newValue = p[jumpoint]->v;
				++jumpoint;
			}
			
			if (newValue > p.back()->v) p.push_back(new node(newWeight, newValue)); //是否是最后一个跳跃点的受控点
			while (p[jumpoint]->v <= p.back()->v && jumpoint <= right) ++jumpoint; //判断下一个跳跃点
		}

		while (jumpoint <= right) //p[i+1] U q[i+1]中的其它跳跃点均为p[i]中的跳跃点
		{
			p.push_back(new node(p[jumpoint]->w, p[jumpoint]->v));
			++jumpoint;
		}

		left = right + 1;
		right = p.size() - 1;

		first[i - 1] = p.size();
	}

	for (int i = 0; i < number; i++)
	{
		int st = first[i + 1], ed = first[i] - 1;
		cout << "[" << st << "," << ed << "]" << endl;
		for (int j = st; j <= ed; ++j)
		{
			cout << "(" << p[j]->w << ", " << p[j]->v << ") ";
		}	
		cout << endl;
	}

	return p.back()->v;
}

void JumpMethod::printItems()
{	
	double nowWeight = p[first[0] - 1]->w;
	double nowValue = p[first[0] - 1]->v;
	
	for (int i = 1; i <= number; i++)
	{
		for (int k = first[i + 1]; k <= first[i] - 1; k++)
		{
			if (equal(p[k]->w + weight[i], nowWeight) && equal(p[k]->v + value[i], nowValue))
			{
				nowWeight = p[k]->w;
				nowValue = p[k]->v;
				cout << i << " ";
				break;
			}
		}
	}

	cout << endl;
}

JumpMethod::JumpMethod(int num, int cap, double* w, double* v) : number(num), capacity(cap), weight(w), value(v)
{
	first.resize(num + 2);
	p.push_back(new node(0, 0));
	
	first[num + 1] = 0;

	cout << sol() << endl;
	printItems();
}

JumpMethod::~JumpMethod()
{
	for (auto* i : p) delete i;
}
