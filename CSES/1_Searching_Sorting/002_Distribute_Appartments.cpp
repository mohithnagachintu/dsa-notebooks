#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<ll> a(n), b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int i = 0, j = 0, ans = 0;
	while (i < n && j < m)
	{
		if (abs(a[i] - b[j]) <= k)
		{
			ans++;
			i++;
			j++;
		}
		else if (a[i] < b[j])
		{
			// ignore this applicant
			i++;
		}
		else
		{
			// ignore this building
			j++;
		}
	}
	cout << ans << '\n';
	return 0;
}

// TC - O(n log n + m log m) for sorting the two arrays
// SC - O(n + m) for storing the two arrays