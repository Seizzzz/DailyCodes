#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
	string name;
	string ID;
	int grade;
};

vector<node> male,female;

bool cmp1(node a, node b)
{
	return a.grade < b.grade;
}
bool cmp2(node a, node b)
{
	return a.grade > b.grade;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		node tmp;
		char c;
		cin >> tmp.name >> c >> tmp.ID >> tmp.grade;
		if (c == 'M') male.push_back(tmp);
		else female.push_back(tmp);
	}

	
	if (!female.empty())
	{
		sort(female.begin(), female.end(), cmp2);
		cout << female[0].name << " " << female[0].ID << endl;
	}
	else cout << "Absent" << endl;

	if (!male.empty())
	{
		sort(male.begin(), male.end(), cmp1);
		cout << male[0].name << " " << male[0].ID << endl;
	}
	else cout << "Absent" << endl;

	if (female.empty() || male.empty()) cout << "NA" << endl;
	else cout << female[0].grade - male[0].grade << endl;

	return 0;
}