#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	string id;
	string name;
	int score;
};

node* student;
int n, c;

bool func1(node a, node b)
{
	return a.id < b.id;
}

bool func2(node a, node b)
{
	if (a.name == b.name) return a.id < b.id;
	return a.name < b.name;
}

bool func3(node a, node b)
{
	if (a.score == b.score) return a.id < b.id;
	return a.score < b.score;
}

void mysort(node* stu)
{
	switch (c)
	{
	case 1: {
		sort(stu, stu + n, func1);
		break;
	}
	case 2: {
		sort(stu, stu + n, func2);
		break;
	}
	case 3: {
		sort(stu, stu + n, func3);
		break;
	}
	}
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n >> c;
	student = new node[n];
	
	for (int i = 0; i < n; ++i)
	{
		cin >> student[i].id >> student[i].name >> student[i].score;
	}

	mysort(student);

	for (int i = 0; i < n; ++i)
	{
		cout << student[i].id << " "
			<< student[i].name << " "
			<< student[i].score << endl;
	}

	delete[] student;

	return 0;
}