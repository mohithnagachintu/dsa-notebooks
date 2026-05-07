// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >>n;

	vector<int> a(n);
	for (int i=0;i<n;i++) cin >> a[i];

	set<int> st;
	int left = 0, right = 0, ans = 0;
	while (right < n && left <= right){
		while (st.find(a[right]) != st.end()){
			st.erase(a[left]);
			left++;
		}
		st.insert(a[right]);
		if (st.size() > ans)
			ans = st.size();
		right++;
	}
	cout << ans << endl;
}