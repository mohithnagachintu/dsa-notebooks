#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // map<ll, int> mp;
    unordered_map<ll, int> mp;

    // Pre-allocate enough buckets to avoid expensive rehash during inserts.
    // With max_load_factor(0.7), target buckets ~= n / 0.7, so 2*n is a safe cushion.
    mp.reserve(2LL * n);
    // Keep bucket occupancy lower (default is usually 1.0) for faster average lookups.
    mp.max_load_factor(0.7f);

    for (int i = 0; i < n; i++)
    {
        auto it = mp.find(x - a[i]);
        if (it != mp.end())
        {
            cout << it->second + 1 << " " << i + 1 << '\n';
            return 0;
        }
        mp[a[i]] = i;
    }
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}

// 1. Using map - ordered map (implemented as a balanced binary search tree) to store the values and their indices.
// TC - O(n log n) for inserting n elements into the map and searching for n elements
// SC - O(n) for storing n elements in the map

// 2. Using unordered_map - hash table to store the values and their indices.
// TC - O(n) on average, O(n^2) in the worst case (heavy collisions)
// SC - O(n) for storing n elements in the unordered_map