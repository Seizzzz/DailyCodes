#include <bits/stdc++.h>
using namespace std;

struct stu
{
	string name;
	string id;
	int sc;
};

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	stu high,low;
	high.sc = -0x3fffffff;
	low.sc = 0x3fffffff;
	while(n--)
	{
		stu tmp;
		cin >> tmp.name >> tmp.id >> tmp.sc;
		if(tmp.sc > high.sc) high = tmp;
		if(tmp.sc < low.sc) low = tmp;
	}
	
	cout << high.name << " " << high.id << endl;
	cout << low.name << " " << low.id << endl;
	 

	return 0;
}

