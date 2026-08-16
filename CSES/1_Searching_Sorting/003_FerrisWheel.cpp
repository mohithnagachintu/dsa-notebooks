#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<ll> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p.begin(), p.end());

    int i = 0, j = n - 1, ans = 0;
    while (i <= j)
    {
        if (p[i] + p[j] <= x)
        {
            ans++;
            i++;
            j--;
        }
        else
        {
            ans++;
            j--;
        }
    }
    cout << ans << '\n';
}

// TC - O(n log n) for sorting the array
// SC - O(n) for storing the array