// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// like rod cutting, after each cut, get the longest rod

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, n;
	cin >> x >> n;

	// this stores length to no. of pieces
	map<ll, ll> mp;
	mp[x] = 1;
	set<int> points = {0, x};

	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		auto it = points.upper_bound(temp);
		int right_point = *it;
		int left_point = *(--it);
		mp[right_point - left_point] -= 1;
		if (mp[right_point - left_point] == 0)
			mp.erase(right_point - left_point);
		points.insert(temp);
		mp[right_point - temp]++;
		mp[temp - left_point]++;
		cout << mp.rbegin()->first << " ";
	}
}