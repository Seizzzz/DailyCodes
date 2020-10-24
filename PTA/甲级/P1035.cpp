#include <iostream>
#include <vector>
using namespace std;

struct node
{
	bool mod;
	string username;
	string password;
};

vector<node> info;

void replace(node& x)
{
	for (unsigned i = 0; i < x.password.length(); ++i)
	{
		switch (x.password[i])
		{
		case '1': {
			x.password[i] = '@';
			break;
		}
		case '0': {
			x.password[i] = '%';
			break;
		}
		case 'l': {
			x.password[i] = 'L';
			break;
		}
		case 'O': {
			x.password[i] = 'o';
			break;
		}
		}
	}
}

int modified(vector<node>& x)
{
	int ans = 0;
	for (auto i = x.begin(); i != x.end(); ++i)
	{
		auto f1 = (i->password).find("1"),
			f0 = (i->password).find("0"),
			fl = (i->password).find("l"),
			fO = (i->password).find("O");
		if (f1 == string::npos && f0 == string::npos && fl == string::npos && fO == string::npos)
		{
			(*i).mod = false;
		}
		else
		{
			replace(*i);
			(*i).mod = true;
			++ans;
		}
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		node tmp;
		cin >> tmp.username >> tmp.password;
		info.push_back(tmp);
	}
	
	int mod = modified(info);

	if (n == 1)
	{
		if (mod == 0)
		{
			cout << "There is 1 account and no account is modified" << endl;
			return 0;
		}
	}
	else if (mod == 0)
	{
		cout << "There are " << n << " accounts and no account is modified" << endl;
		return 0;
	}

	cout << mod << endl;
	for (int i = 0; i < info.size(); ++i)
	{
		if (info[i].mod) cout << info[i].username << " " << info[i].password << endl;
	}

	return 0;
}