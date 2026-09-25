#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Range Update Queries
class FenwickTree
{
private:
    vector<ll> bit;
    int n;

public:
    FenwickTree(int size)
    {
        n = size;
        bit.resize(n + 1);
    }

    void update(int i, ll delta)
    {
        while (i <= n)
        {
            bit[i] += delta;
            i += (i & -i);
        }
    }

    ll query(int i)
    {
        ll total = 0;
        while (i > 0)
        {
            total += bit[i];
            i -= (i & -i);
        }
        return total;
    }

    ll range_query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> nums(n + 1);
    FenwickTree fenwickTree(n);

    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        ll diff = nums[i] - nums[i - 1];
        fenwickTree.update(i, diff);
    }

    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            // add u to [a,b]
            fenwickTree.update(a, u);
            fenwickTree.update(b + 1, -u);
        }
        else
        {
            int k;
            cin >> k;

            cout << fenwickTree.query(k) << "\n";
        }
    }

    return 0;
}