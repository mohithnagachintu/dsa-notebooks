// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(int pos,
         int started,
         int tight,
         int count,
         string &s,
         ll (&dp)[19][2][2][4])
{
    if (count > 3)
        return 0;

    if (pos == (int)s.size())
        return 1;

    if (dp[pos][started][tight][count] != -1)
        return dp[pos][started][tight][count];

    ll ans = 0;

    int max_digit_for_i;
    if (tight == 1)
        max_digit_for_i = s[pos] - '0';
    else
        max_digit_for_i = 9;

    for (int d = 0; d <= max_digit_for_i; d++) {

        // CASE 1: number already started
        if (started == 1) {

            int new_count = (d == 0) ? count : count + 1;
           
            if (tight == 1 && d == max_digit_for_i) {
                ans += solve(pos + 1, 1, 1, new_count, s, dp);
            } else {
                ans += solve(pos + 1, 1, 0, new_count, s, dp);
            }
        }

        // CASE 2: number not started yet
        else {

            // still leading zero
            if (d == 0) {
                if (tight == 1 && d == max_digit_for_i) {
                    ans += solve(pos + 1, 0, 1, count, s, dp);
                } else {
                    ans += solve(pos + 1, 0, 0, count, s, dp);
                }
            }
            // first non-zero digit
            else {
                if (tight == 1 && d == max_digit_for_i) {
                    ans += solve(pos + 1, 1, 1, count + 1, s, dp);
                } else {
                    ans += solve(pos + 1, 1, 0, count + 1, s, dp);
                }
            }
        }
    }

    return dp[pos][started][tight][count] = ans;
}

ll count_classy(ll x) {
    if (x < 0)
        return 0;

    string s = to_string(x);
    ll dp[19][2][2][4];
    memset(dp, -1, sizeof(dp));

    return solve(0, 0, 1, 0, s, dp);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll L, R;
        cin >> L >> R;
        cout << count_classy(R) - count_classy(L - 1) << "\n";
    }

    return 0;
}
