// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	 	cin >> a[i];

	ll ans = 0;
	int left = 0, right = 0;
	set<int> st;

	while (right < n && left <= right){
		while (st.find(a[right]) != st.end()){
			st.erase(a[left]);
			left++;
		}
		st.insert(a[right]);
		ans += (right - left + 1);
		right++;
	}
	cout << ans << endl;
}