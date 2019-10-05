#include <bits/stdc++.h>
using namespace std;

struct term
{
	int c;
	int e;
};

int main()
{
	std::ios::sync_with_stdio(false);
	
	vector<term> line;
	term tmp;
	while(cin >> tmp.c >> tmp.e) line.push_back(tmp);
	
	for(vector<term>::iterator ptr= line.begin();ptr<line.end();++ptr)
	{
		(*ptr).c *= (*ptr).e;
		if((*ptr).e) --(*ptr).e;
	}
	
	cout << line.front().c << " " << line.front().e;
	for(vector<term>::iterator ptr= line.begin()+1;ptr!=line.end();++ptr)
	{
		if((*ptr).c != 0) cout << " " << (*ptr).c << " " << (*ptr).e;
	}
	
	cout << endl;

	return 0;
}

