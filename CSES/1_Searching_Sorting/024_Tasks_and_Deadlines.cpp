// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

bool compare(pii &a, pii &b){
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pii> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end(), compare);

	ll ans = 0, time = 0;
	for (int i=0;i<n;i++){
		time += a[i].first;
		ans += (a[i].second - time);
	}
	cout << ans << endl;
	return 0;
}