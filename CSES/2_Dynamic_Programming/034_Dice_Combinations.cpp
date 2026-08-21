// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

int solve(int n, vector<int> &dp)
{
	// Base case
	if (n < 0)
	{
		// Not possible
		return 0;
	}
	if (n == 0)
	{
		// one possible way
		return 1;
	}

	// DP Check
	// if (dp.find(n) != dp.end())
	// 	return dp[n];
	if (dp[n] != -1)
		return dp[n];

	int ans = 0;
	for (int i = 1; i <= 6; i++)
	{
		ans += solve(n - i, dp);
		if (ans >= MOD)
			ans -= MOD;
	}
	dp[n] = ans;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	// unordered_map<int,int> dp;
	// dp.reserve(n);
	// dp.max_load_factor(0.7);

	// Recursion + 1D DP
	// vector<int> dp(n+1,-1);
	// int ans = solve(n,dp);
	// cout << ans << endl;

	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int x = 1; x <= n; x++)
	{
		int ans = 0;
		for (int i = 0; i <= 6; i++)
		{
			if (x - i >= 0)
			{
				ans += dp[x - i];
				if (ans >= MOD)
					ans -= MOD;
			}
		}
		dp[x] = ans;
	}
	cout << dp[n] << endl;
}