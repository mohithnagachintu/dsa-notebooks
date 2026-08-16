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

	// why not set, because equal is also not allowed
	multiset<int> st;

	for (int i = 0; i < n; i++)
	{
		// O(log n) for finding the upper bound
		auto itr = st.upper_bound(a[i]);
		if (itr != st.end())
		{
			// O(log n) for erasing the element from the multiset
			st.erase(itr);
		}
		// O(log n) for inserting the element into the multiset
		st.insert(a[i]);
	}
	cout << st.size();
}

// TC - O(n + n log n) for iterating through the array and inserting and erasing elements from the multiset
// SC - O(n) for storing elements in the multiset