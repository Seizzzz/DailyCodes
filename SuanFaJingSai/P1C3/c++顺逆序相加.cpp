#include <iostream>
#include <cstdio>

#include <sstream>
using namespace std;

int main()
{
	string line;
	
	while(getline(cin,line))
	{
		int sum=0,temp;
		stringstream input(line);
		
		while(input >> temp) sum+=temp;
		
		cout << sum << endl;
	} //Ä£ÄâÊäÈë
	
	return 0;
}

