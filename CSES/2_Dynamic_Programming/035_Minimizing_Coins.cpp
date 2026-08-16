// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll min(ll a,ll b){
	return a < b ? a : b;
}

const ll MAXI = 1e8;

// Memo will TLE
// int solve(int i, int n, int s, vector<int> &arr, vector<vector<int>> &dp){
// 	if (i == n){
// 		return (s==0) ? 0 : MAXI;
// 	}
// 	if (dp[i][s] != -1)
// 		return dp[i][s];

// 	ll pick = MAXI;
// 	if (s >= arr[i]){
// 		pick = solve(i,n,s-arr[i],arr,dp) + 1;
// 	}
// 	ll dont_pick = solve(i+1,n,s,arr,dp);
// 	return dp[i][s] = min(pick, dont_pick);
// }

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, s;
	cin >> n >> s;

	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];

	/* Memoization  
	vector<vector<int>> dp(n+1, vector<int>(s+1,-1));
	int ans = solve(0,n,s,a, dp);
	if (ans >= MAXI)
		cout << -1  << endl;
	else
		cout << ans << endl;
	*/


	/* Iterative 2D DP 
	vector<vector<int>> dp(n+1, vector<int>(s+1,MAXI));
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i=n-1;i>=0;i--){
    	for (int j=1; j<=s; j++){
    		dp[i][j] = dp[i+1][j];
    		if (a[i] <= j){
    			dp[i][j] = min(dp[i][j], 1 + dp[i][j-a[i]]);
    		}
    	}
    }
	int ans = dp[0][s];
	if (ans >= MAXI)
		cout << -1  << endl;
	else
		cout << ans << endl;
	*/

	/* Space optimized 2D DP 
	vector<int> dp_next(s+1,MAXI), dp_curr(s+1,MAXI);
	dp_next[0] = 0;
	for (int i=n-1;i>=0;i--){
		dp_curr[0] = 0;
		for (int j=1;j<=s;j++){
			dp_curr[j] = dp_next[j];
			if (a[i] <= j){
				dp_curr[j] = min(dp_curr[j], 1 + dp_curr[j-a[i]]);
			}
		}
		dp_next = dp_curr;
	}
	int ans = dp_next[s];
	if (ans >= MAXI)
		cout << -1  << endl;
	else
		cout << ans << endl;
	*/

}