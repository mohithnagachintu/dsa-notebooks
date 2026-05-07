// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	
	multiset<ll> st;
	for (int i=0;i<n;i++){
		auto it = st.upper_bound(a[i]);
		if (it != st.end()){
			st.erase(it);
		}
		st.insert(a[i]);
	}
	cout << st.size() << endl;
}