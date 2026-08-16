#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	set<int> st;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		st.insert(x);
	}
	cout << st.size() << "\n";
	return 0;
}

// TC - O(n log n) for inserting n elements into the set
// SC - O(n) for storing n elements in the set