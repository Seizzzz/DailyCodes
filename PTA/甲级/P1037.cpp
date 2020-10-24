#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> coupon,product;
int ans = 0;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int n,t;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		coupon.push_back(t);
	}
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		product.push_back(t);
	}

	if (coupon.empty() || product.empty())
	{
		cout << 0 << endl;
		return 0;
	}

	sort(coupon.begin(), coupon.end(), cmp);
	sort(product.begin(), product.end(), cmp);

	unsigned c1 = 0, p1 = 0;
	while (coupon[c1] > 0 && product[p1] > 0)
	{
		int t = coupon[c1++] * product[p1++];
		if (t > 0) ans += t;
		else break;
	}
	unsigned c2 = coupon.size() - 1, p2 = product.size() - 1;
	while (coupon[c2] < 0 && product[p2] < 0)
	{
		int t = coupon[c2--] * product[p2--];
		if (t > 0) ans += t;
		else break;
	}

	cout << ans << endl;

	return 0;
}