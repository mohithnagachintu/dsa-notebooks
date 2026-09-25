#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Standard Fenwick Tree Example - Basic

class FenwickTree
{
private:
    vector<ll> bit;
    int n;

public:
    FenwickTree(int size)
    {
        bit.resize(size + 1);
        n = size;
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
    FenwickTree fenwickTree(n);
    vector<ll> values(n + 1);

    ll x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        values[i] = x;
        fenwickTree.update(i, x);
    }

    int op, l;
    ll r;
    while (q--)
    {
        cin >> op >> l >> r;

        if (op == 1)
        {
            fenwickTree.update(l, r - values[l]);
            values[l] = r;
        }
        else
        {
            cout << fenwickTree.range_query(l, r) << "\n";
        }
    }
    return 0;
}