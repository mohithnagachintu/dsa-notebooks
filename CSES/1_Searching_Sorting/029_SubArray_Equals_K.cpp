// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];

	ll running_sum = 0, ans = 0;
	map <ll, int> mp;
	
	mp[0] = 1;   
	// represents the empty prefix before the array starts, allowing us to count subarrays that begin at index 0.

	for(int i=0;i<n;i++){
		running_sum += a[i];
		if (mp.find(running_sum - x) != mp.end()){
			ans += mp[running_sum - x];
		}
		mp[running_sum] += 1;
	}
	cout << ans << endl;
	return 0;
}
