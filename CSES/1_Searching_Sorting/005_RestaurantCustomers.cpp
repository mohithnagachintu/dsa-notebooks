#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Line Sweep Algorithm

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> a;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a.push_back({x, 1});
		a.push_back({y, -1});
	}
	sort(a.begin(), a.end());
	int ans = 0, count = 0;
	for (auto x : a)
	{
		count += x.second;
		ans = max(ans, count);
	}
	cout << ans << '\n';
	return 0;
}

// TC - O(n log n) - Sorting the array of events
// SC - O(n) - Storing the events in the array