#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	int now=0,next,time=0,t;
	cin >> t;
	
	while(t--)
	{
		cin >> next;
		if(next > now) time += 6*(next-now);
		else time += 4*(now-next);
		now = next;
		time += 5;
	}
	
	cout << time << endl;

	return 0;
}

