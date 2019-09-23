#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	double w,t,l;
	double val[3];
	
	int line=0;
	while(line<3)
	{
		cin >> w >> t >> l;
		val[line++]=max(w,max(t,l));
		
		if(w>t && w>l) cout << "W";
		else if(t>l) cout << "T";
		else cout << "L";
		cout << " ";
	}
	
	cout << setprecision(2) << fixed << 2*(val[0]*val[1]*val[2]*0.65-1) << endl;

	return 0;
}

