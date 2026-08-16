#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), pos(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int rounds = 1;
    for (int i = 2; i <= n; i++)
    {
        if (pos[i] < pos[i - 1])
            rounds++;
    }

    while (m--)
    {
        int i, j;
        cin >> i >> j;
        i--;
        j--;

        set<int> temp = {a[i], a[i] + 1, a[j], a[j] + 1};
        for (int v : temp)
        {
            if (v >= 2 && v <= n && pos[v] < pos[v - 1])
            {
                rounds--;
                // undo rounds if added, add rounds after swap
            }
        }
        swap(a[i], a[j]);
        pos[a[j]] = j;
        pos[a[i]] = i;

        for (int v : temp)
        {
            if (v >= 2 && v <= n && pos[v] < pos[v - 1])
            {
                rounds++;
            }
        }
        cout << rounds << '\n';
    }
    return 0;
}

// TC - O(n + m) for iterating through the array and storing positions and processing m queries
// SC - O(n) for storing positions of n elements