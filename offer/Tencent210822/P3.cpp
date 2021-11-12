#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

/*
1
10 6
1 2 2 1 3 3 2 3 1 5
*/

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n, w;
		cin >> n >> w;
		vector<int> weight(n);
		for (int i = 0; i < n; ++i) cin >> weight[i];

		int need = 0;
		
		vector<bool> isLoaded(n);
		for (int i = 0; i < n; ++i) isLoaded[i] = false;

		for(int now = 0; now < n; ++now) //zhu ge bian li
		{
			if(isLoaded[now]) continue;

			int nowmax = -1;
			int nowpos = -1;

			for(int may = 0; may < n; ++may)
			{
				if (may == now) continue;
				int weight_t = weight[now] + weight[may];
				if(!isLoaded[may] && (weight_t % 2 == 0) && (weight_t <= w))
				{
					if(weight_t > nowmax)
					{
						nowmax = weight_t;
						nowpos = may;
					}
				}
			}

			if(nowpos != -1) //2 ren
			{
				isLoaded[now] = true;
				isLoaded[nowpos] = true;
				++need;
			}
			else //1 ren
			{
				isLoaded[now] = true;
				++need;
			}
		}

		cout << need << endl;
	}
}