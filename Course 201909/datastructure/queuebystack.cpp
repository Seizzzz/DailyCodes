#include <bits/stdc++.h>
using namespace std;

template<typename T> class que
{
	stack<T> S1,S2;
	
	public:
	void Enqueue(T x)
	{
		S1.push(x);
		return;
	} 

	void Dequeue()
	{
		if(S1.empty()) exit(-1);
		while(S1.size()!=1)
		{
			S2.push(S1.top());
			S1.pop();
		}
		S1.pop(); //S1.clear()
		while(!S2.empty())
		{
			S1.push(S2.top());
			S2.pop();
		}
		return;
	} 
	
	bool emptyq()
	{
		return S1.empty();
	}
	
	T top()
	{
		return S1.top();
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	
	que<int> q1;
	q1.Enqueue(23);
	q1.Enqueue(25);
	cout << q1.top() << endl;
	q1.Dequeue();
	cout << q1.top() << endl;
	q1.Dequeue();
	cout << q1.emptyq() << endl;

	return 0;
}

