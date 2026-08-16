#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cost(vector<ll> &a, int n, ll median)
{
    ll temp = 0;
    for (int i = 0; i < n; i++)
        temp += abs(a[i] - median);
    return temp;
}

// Median - always minimizes the sum of absolute differences from a set of numbers.
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll median = a[n / 2];
    cout << cost(a, n, median) << '\n';
    return 0;
}

// TC - O(n log n) for sorting the array
// SC - O(n) for storing n elements in the array