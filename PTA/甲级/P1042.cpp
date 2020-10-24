#include <iostream>
#include <vector>
using namespace std;

int method[55];

void shuffle(vector<int>& pile)
{
	vector<int> newpile(55);
	for (int i = 1; i <= 54; ++i)
	{
		newpile[method[i]] = pile[i];
	}
	pile = newpile;
	return;
}

int main()
{
	ios::sync_with_stdio(false);

	int times; cin >> times;
	for (int i = 1; i <= 54; ++i) cin >> method[i];

	vector<int> pile(55);
	for (int i = 1; i <= 54; ++i) pile[i] = i;
	for (int i = 0; i < times; ++i) shuffle(pile);

	for (int i = 1; i <= 54; ++i)
	{
		switch ((pile[i] - 1) / 13)
		{
		case 0: {
			cout << "S";
			break;
		}
		case 1: {
			cout << "H";
			break;
		}
		case 2: {
			cout << "C";
			break;
		}
		case 3: {
			cout << "D";
			break;
		}
		case 4: {
			cout << "J";
			break;
		}
		}
		cout << ((pile[i] - 1) % 13) + 1;
		if (i != 54) cout << " ";
	}

	return 0;
}