#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	sort(x.begin(), x.end());

	ll s = 1;
	for (int i = 0; i < n; i++)
	{
		if (x[i] > s)
			break;
		s += x[i];
	}
	cout << s << '\n';
	return 0;
}