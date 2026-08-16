#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	set<int> st;
	int count = 0, ans = 0, left = 0;

	for (int right = 0; right < n; right++)
	{
		while (st.find(a[right]) != st.end())
		{
			st.erase(a[left]);
			left++;
			count--;
		}
		st.insert(a[right]);
		count++;
		ans = max(ans, count);
	}
	cout << ans;
	return 0;
}

// TC - O(n) for iterating through the array and storing elements in set
// SC - O(n) for storing elements in set