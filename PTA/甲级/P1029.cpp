#include <iostream>
#include <queue>
#define inf 0x7fffffff
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	queue<long> a, b;
	long n1, n2;
	cin >> n1;
	for (int i = 0; i < n1; ++i)
	{
		long t; cin >> t;
		a.push(t);
	}
	a.push(inf);
	cin >> n2;
	for (int i = 0; i < n2; ++i)
	{
		long t; cin >> t;
		b.push(t);
	}
	b.push(inf);

	int mid = (a.size() + b.size() - 2) / 2;
	if((a.size() + b.size()) % 2 == 0) --mid;
	for (int i = 0; i < mid; ++i)
	{
		if (a.front() > b.front()) b.pop();
		else a.pop();
	}

	cout << ((a.front() < b.front()) ? a.front() : b.front()) << endl;

	return 0;
}