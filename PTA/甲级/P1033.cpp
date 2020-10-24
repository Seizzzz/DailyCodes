#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int capacity, dis, stationnum;
double disperoil;

struct node
{
	double price;
	int pos;
};

bool cmp(node a, node b)
{
	return a.pos < b.pos;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> capacity >> dis >> disperoil >> stationnum;

	vector<node> station;
	for (int i = 0; i < stationnum; ++i)
	{
		node tmp; cin >> tmp.price >> tmp.pos;
		station.push_back(tmp);
	}
	sort(station.begin(), station.end(), cmp);

	int nowat = 0, nowtank = 0;
	while (true)
	{
		double leastfar = nowat, mostfar = nowat + nowtank * disperoil;
		for (int i = 0; i < stationnum; ++i) //±éÀú¼ÓÓÍÕ¾
		{
			if (station[i].pos >= leastfar)
			{
				if (station[i].pos <= mostfar)
				{

				}
				else break;
			}
		}
	}



	return 0;
}