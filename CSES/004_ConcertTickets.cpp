// #include "bits_std_mac.h"
#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <algorithm>
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;
	vector<ll> t(m);
	multiset<ll> h;
	ll x;


	for(int i=0;i<n;i++){
		cin >> x;
		h.insert(x);
	}
	// TC - O(n log n)

	for(int i=0;i<m;i++) 
		cin >> t[i];
	// TC - O(m)

	for (int i=0; i < m; i++){
		auto it = h.upper_bound(t[i]);  // O(log n)

		if (it == h.begin()){
			// doesn't exits;
			cout << -1 << " ";
		} else {
			--it;
			cout << *it << " ";
			h.erase(it);     // O(log n)
		}
	}
	// TC - O (m * (log n + logn) = O(mlogn))
	return 0;
	// Overall TC - O((m+n) logn)
}