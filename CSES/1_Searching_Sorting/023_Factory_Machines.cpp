// #include <bits/stdc++.h>
#include "bits_std_mac.h"
using namespace std;

using ll = long long;

// Rule of thumb: If the answer is up to 1e18, never simulate events.
// Constraints: 
//  n <= 2e5
//  t <= 1e9 - products
//  a[i] <= 1e9 - seconds
// Worst case - 1e9 * 1e9 ~ 1e18
// Binary search - “Is time T enough to produce at least t products?”

ll solve(const vector<ll> &a, ll mid, ll t) {
    ll produced = 0;
    for (auto &x : a) {
        produced += mid / x;
        if (produced >= t)
            break;
    }
    return produced;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, t;
    cin >> n >> t;

    vector<ll> a(n);
    ll maxi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }

    ll low = 0, high = maxi * t;

    while (low < high) {
        ll mid = low + (high - low) / 2;
        ll produced = solve(a, mid, t);

        if (produced >= t)
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << '\n';
    return 0;
}
