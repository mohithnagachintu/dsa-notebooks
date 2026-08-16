// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;
 
using ll =  long long;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
 	int n, k;
 	ll x, a, b, c;	
	cin >> n >> k >> x >> a >> b >> c;
 

	// Idea - queue [min, max]
	deque <pair<ll,int>> dq;
	ll ans = 0;
	for (int i=0;i<n;i++){
		// if x < last, remove it
		while (!dq.empty() && dq.back().first >= x){
			dq.pop_back();
		}
		dq.push_back({x,i});
		// if queue size at mask k
		while (!dq.empty() && dq.front().second <= i-k){
			dq.pop_front();
		}	
		// if window = k, take the min
		if (i >= k-1){
			ans = ans ^ dq.front().first;
		}
		// next x
		x = (a * x + b) % c;
	}

	cout << ans << endl;
	return 0;
}
