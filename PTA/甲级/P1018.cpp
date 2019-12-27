#include <bits/stdc++.h>
using namespace std;

int capacity,station,problem,road;

int main()
{
	std::ios::sync_with_stdio(false);
	
	map<int,int> mymap; 
	
	cin >> capacity >> station >> problem >> road;
	for(int i=0;i<station;++i)
	{
		int num;
		cin >> num;
		mymap.insert(map<int,int>::value_type(i,num));
	}
	
	

	return 0;
}

