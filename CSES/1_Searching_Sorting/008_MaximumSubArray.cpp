#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Standard Kadane's algorithm
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll temp = 0, ans = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		temp += a[i];
		if (temp > ans)
			ans = temp;
		if (temp < 0)
			temp = 0;
	}
	cout << ans << '\n';
	return 0;
}

// TC - O(n) for iterating through the array once
// SC - O(1) for using constant space for variables