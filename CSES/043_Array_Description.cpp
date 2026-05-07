// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1000000007;

// int solve(int i,int prev_value,int n,int m,vector<int> &a,vector<vector<int>> &dp){
// 	if (i == n)
// 		return 1;
// 	if (dp[i][prev_value] != -1)
// 		return dp[i][prev_value];

// 	int ans = 0;
// 	if (a[i] != 0){
// 		// value known
// 		if (abs(a[i]-prev_value) <=1){
// 			ans = solve(i+1,a[i],n,m,a,dp);
// 			if (ans >= MOD)
// 				ans -= MOD;
// 		}
// 	} else {
// 		// value unknown
// 		for (int j=1;j<=m;j++){
// 			if (abs(j-prev_value) <= 1){
// 				ans += solve(i+1,j,n,m,a,dp);
// 				if (ans >= MOD)
// 					ans -= MOD;
// 			}
// 		}
// 	}
// 	return dp[i][prev_value] = ans;
// }

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];

	/* Recursive 2D DP 
	vector<vector<int>> dp(n,vector<int>(m+1,-1));
	int ans = 0;
	if (a[0] != 0){
		ans = solve(1,a[0],n,m,a,dp);
	} else {
		for (int j=1;j<=m;j++){
			ans += solve(1,j,n,m,a,dp);
			if (ans >= MOD)
				ans -= MOD;
		}
	}
	cout << ans << endl; 
	*/

	/* Iterative 2D DP 
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for (int j=1;j<=m;j++)
		dp[n][j] = 1;
	for (int i=n-1;i>=1;i--){
		for (int prev_value=1;prev_value<=m;prev_value++){
			int ans = 0;
			if (a[i] != 0){
				// value known
				if (abs(a[i]-prev_value) <= 1){
					ans = dp[i+1][a[i]];
				}
			} else {
            	for (int j = max(1, prev_value - 1);j <= min(m, prev_value + 1);j++) {
	                ans += dp[i+1][j];
	                if (ans >= MOD) 
	                	ans -= MOD;
	            }
			}
			dp[i][prev_value] = ans;
		}
	}
	ll ans = 0;
	if (a[0] != 0)
		ans = dp[1][a[0]];
	else{
		for (int j=1;j<=m;j++){
			ans += dp[1][j];
			if (ans >= MOD)
				ans -= MOD;
		}
	}
	cout << ans << endl;
	*/

	/* Space Optimized DP*/
	vector<int> curr(m+1,0), next(m+1,0);
	for (int j=1;j<=m;j++)
		next[j] = 1;
	for (int i=n-1;i>=1;i--){
		for (int prev_value=1;prev_value<=m;prev_value++){
			int ans = 0;
			if (a[i] != 0){
				// value known
				if (abs(a[i]-prev_value) <= 1){
					ans = next[a[i]];
				}
			} else {
				// value unknown
            	for (int j = max(1, prev_value - 1);j <= min(m, prev_value + 1);j++) {
	                ans += next[j];
	                if (ans >= MOD) 
	                	ans -= MOD;
	            }
			}
			curr[prev_value] = ans;
		}
		next = curr;
	}
	ll ans = 0;
	if (a[0] != 0)
		ans = next[a[0]];
	else{
		for (int j=1;j<=m;j++){
			ans += next[j];
			if (ans >= MOD)
				ans -= MOD;
		}
	}
	cout << ans << endl;

}