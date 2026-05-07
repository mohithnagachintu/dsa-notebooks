// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<long long, long long>;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x,temp;
    cin >> n >> x;

    unordered_map<ll,ll> mp;
    mp.reserve(n);           // important
    mp.max_load_factor(0.7); // reduces collisions
    for (int i=0;i<n;i++){
        cin >> temp;
        if (mp.find(x-temp) != mp.end()){
            cout << mp[x-temp] << " " << i + 1 << endl;
            return 0;
        } else {
            mp[temp] = i+1;
        }
    }   
    cout << "IMPOSSIBLE" << endl;
       
}