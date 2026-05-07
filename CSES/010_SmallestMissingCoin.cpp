// #include "bits_std_mac.h"
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i=0;i<n;i++) cin >> a[i];
	sort(a.begin(), a.end());

	ll s=1;
	for(int i=0;i<n;i++){
		if (a[i] > s)
			break;
		s += a[i];
	}
	cout << s << endl;
}