// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pli = pair<ll,int>;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, x;
	cin >> n >> x;
	vector <pli> a(n);

	for (int i=0;i<n;i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());

	vector<int> ans;
	for (int j=0;j<n;j++){
		for (int i=j+1;i<n;i++){
			ll temp = a[j].first + a[i].first;		
			int left = i+1, right = n - 1;
			while (left < right){
				if (a[left].first + a[right].first + temp == x){
					ans = {a[j].second, a[i].second, a[left].second, a[right].second};
					break;
				}
				else if (a[left].first + a[right].first + temp > x){
					right--;
				}
				else if (a[left].first + a[right].first + temp < x){
					left++;
				}
			}
			if (ans.size() > 0)
				break;
		}
		if (ans.size() > 0)
				break;
	}
	sort(ans.begin(), ans.end());
	if (ans.size() > 0)
		cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
	else
		cout << "IMPOSSIBLE" << endl;
}

