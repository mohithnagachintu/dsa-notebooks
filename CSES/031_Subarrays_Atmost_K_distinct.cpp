// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) 
    	cin >> x;

    unordered_map<int,int> mp;
	
  	ll ans = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        mp[a[right]]++;

        while ((int)mp.size() > k) {
            mp[a[left]]--;
            if (mp[a[left]] == 0)
                mp.erase(a[left]);
            left++;
        }

        ans += (right - left + 1);
    }

    cout << ans << '\n';
}
