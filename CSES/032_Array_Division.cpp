#include "bits_std_mac.h"
// #include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
bool solve(vector<ll> &a, int n,int k, ll maxi){
	ll temp = 1, s = 0;
 
	for (int i=0;i<n;i++){
		if (a[i] > maxi)
			return false;
 
		if (s + a[i] <= maxi) {
			s += a[i];
		} else {
			temp++;
			s = a[i];
		}
	}
	return temp <= k;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n, k; 
	cin >> n >> k;
 
	vector<ll> a(n);
	ll low = 1, high = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		high += a[i];
	}
 
	while (low <= high){
		ll mid = low + (high - low) / 2;
		if (solve(a,n,k,mid)){
			high = mid - 1;
		}
		else low = mid + 1;
	}
	cout << low << endl;
	return 0;
}
