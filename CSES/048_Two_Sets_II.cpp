// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

// int solve(int i,int n,ll s,vector<int> &a,vector<vector<int>> &dp){
// 	// base case
// 	if (s == 0)
// 		return 1;
// 	if (i == n)
// 		return 0;
// 	if (dp[i][s] != -1)
// 		return dp[i][s];
// 	// choices
// 	int pick = 0;
// 	if (a[i] <= s)
// 		pick = solve(i+1,n,s-a[i],a,dp);
// 	int dont_pick = solve(i+1,n,s,a,dp);
// 	int ans =  pick + dont_pick;
// 	if (ans >= MOD)
// 		ans -= MOD;
// 	dp[i][s] = ans;
// 	return ans;
// }

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	ll sum = n * (n+1) / 2;
	if (sum & 1){
		cout << 0 << endl;
		return 0;
	}
	ll half_sum = sum / 2;
	for(int i=0;i<n;i++)
		a[i] = i+1;
	
	// Recursive + Memo 2D DP
	// vector<vector<int>> dp(n+1,vector<int>(half_sum+1,-1));
	// int ways = solve(0,n,half_sum,a,dp);
	// ll inv2 = (MOD + 1) / 2;
	// cout << (ways * inv2) % MOD << endl;

	// Iterative 2D DP
	// vector<vector<int>> dp(n+1,vector<int>(half_sum+1,0));
	// for (int i=n;i>=0;i--)
	// 	dp[i][0] = 1;
	// for (int i=n-1;i>=0;i--){
	// 	for (int s = 1; s <= half_sum; s++){
	// 		int pick = 0;
	// 		if (a[i] <= s)
	// 			pick = dp[i+1][s-a[i]];
	// 		int dont_pick = dp[i+1][s];
	// 		int ans =  pick + dont_pick;
	// 		if (ans >= MOD)
	// 			ans -= MOD;
	// 		dp[i][s] = ans;
	// 	}
	// }
	// int ways = dp[0][half_sum];
	// ll inv2 = (MOD + 1) / 2;
	// cout << (ways * inv2) % MOD << endl;

	// Space Optimized 1D DP
	vector<int> curr(half_sum+1,0),next(half_sum+1,0);
	next[0] = 1;
	curr[0] = 1;
	
	for (int i=n-1;i>=0;i--){
		for (int s = 1; s <= half_sum; s++){
			int pick = 0;
			if (a[i] <= s)
				pick = next[s-a[i]];
			int dont_pick = next[s];
			int ans =  pick + dont_pick;
			if (ans >= MOD)
				ans -= MOD;
			curr[s] = ans;
		}
		next = curr;
	}
	int ways = next[half_sum];
	ll inv2 = (MOD + 1) / 2;
	cout << (ways * inv2) % MOD << endl;
}

