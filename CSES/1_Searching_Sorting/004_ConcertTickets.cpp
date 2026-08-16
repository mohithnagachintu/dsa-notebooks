#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	multiset<ll> h;
	for (int i=0;i<n;i++) {
		int x;
		cin >> x;
		h.insert(x);
	}
	vector<ll> t(m), ans(m,-1);
	for (int i=0;i<m;i++) cin >> t[i];
	for (int i=0;i<m;i++){
		auto it = h.upper_bound(t[i]);
		if (it != h.begin()){
			--it;
			ans[i] = *it;
			h.erase(it);
		}
	}
	for (int i=0;i<m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}

// TC - O(n log n + m log n) for inserting n elements into the multiset and searching for m elements
// SC - O(n) for storing n elements in the multiset