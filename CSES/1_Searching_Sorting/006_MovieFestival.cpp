#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;

static bool comp(const pll &a, const pll &b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<ll, ll>> intervals(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		intervals[i] = {x, y};
	}

	// sorting by end value, because we need to select the interval which ends first
	//  so that we can select more intervals after it
	sort(intervals.begin(), intervals.end(), comp);

	int ans = 0, end = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (intervals[i].first >= end)
		{
			ans++;
			end = intervals[i].second;
		}
	}
	cout << ans << '\n';
}

// TC - O(n log n) for sorting the intervals
// SC - O(n) for storing n intervals
