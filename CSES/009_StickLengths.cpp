// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll median = a[n / 2];
    ll cost = 0;

    for (ll x : a)
        cost += abs(x - median);

    cout << cost << "\n";
    return 0;
}