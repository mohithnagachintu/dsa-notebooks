

// #include "bits_std_mac.h"
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pll> a;
	ll temp;

	for (int i=0;i<n;i++){
		cin >> temp;
		a.push_back({temp,1});
		cin >> temp;
		a.push_back({temp,-1});
	}
	sort(a.begin(), a.end());
	int s = 0, ans = 0;
	for (auto &i: a){
		s += i.second;
		if (s > ans)
			ans = s;
	}
	cout << ans << endl;

}