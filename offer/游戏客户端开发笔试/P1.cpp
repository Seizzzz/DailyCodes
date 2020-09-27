#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
using namespace std;

int n;
vector<int> Pos;
vector<int> Dir;
vector<int> Res;
int R, Q;
int x, y;



void solve(int n, vector<int>& pos, vector<int>& dir, int r, int q) {
	// 
	double rangeView = q * acos(-1) / 180;
	int view_x = dir[0], view_y = dir[1];
	for (int i = 0; i < 2 * n; i = i + 2)
	{
		int x = pos[i]; int y = pos[i + 1];
		double lenToActor2 = pow(x, 2) + pow(y, 2);
		double lenToActor = sqrt(lenToActor2);
		double lenToView2 = pow(view_x, 2) + pow(view_y, 2);
		double lenToView = sqrt(lenToView2);
		double lenActorToView2 = pow(x - view_x, 2) + pow(y - view_y, 2);
		double arc = acos((lenToActor2 + lenToView2 - lenActorToView2) / (2 * lenToActor * lenToView));
		if (lenToActor < (double)r && arc < rangeView) //在半径内 且在视野内
		{
			Res.push_back(i/2);
			//Res.push_back(x);
			//Res.push_back(y);
		}
	}

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		Pos.push_back(x);
		Pos.push_back(y);
	}
	cin >> x >> y;
	Dir.push_back(x);
	Dir.push_back(y);
	cin >> R >> Q;

	solve(n, Pos, Dir, R, Q);
	//for (auto res : Res) cout << res << " ";
	for (auto i : Res) cout << i << " ";
	cout << endl;

	return 0;
}