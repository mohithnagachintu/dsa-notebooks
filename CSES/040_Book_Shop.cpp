// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// int solve(int i,int n, int x, vector<int> &h,vector<int> &s,vector<vector<int>> &dp){
// 	if (i == n){
// 		return 0;
// 	}
// 	if (dp[i][x] != -1)
// 		return dp[i][x];
// 	int pick = 0;
// 	if (h[i] <= x)
// 		pick = solve(i+1,n,x-h[i],h,s,dp) + s[i];
// 	int dont_pick = solve(i+1,n,x,h,s,dp);
// 	return dp[i][x] = max(pick,dont_pick);
// }

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,x;
	cin >> n >> x;

	vector<int> h(n), s(n);
	for(int i=0;i<n;i++)
		cin >> h[i];
	for(int i=0;i<n;i++)
		cin >> s[i];

	// TLE for Memo + DP
	// vector<vector<int>> dp(n,vector<int>(x+1,-1));
	// cout << solve(0,n,x,h,s,dp) << endl;

	// Iterative 2D DP
	// vector<vector<int>> dp(n+1,vector<int>(x+1,0));
	// for (int i=n-1;i>=0;i--){
	// 	for (int j=0;j<=x;j++){
	// 		int pick = 0;
	// 		if (h[i] <= j)
	// 			pick = dp[i+1][j-h[i]] + s[i];
	// 		int dont_pick = dp[i+1][j];
	// 		dp[i][j] = max(pick, dont_pick);
	// 	}
	// }
	// cout << dp[0][x] << endl;

	// Space optimized 2D DP
	// vector<int> curr(x+1,0), next(x+1,0);
	// for (int i=n-1;i>=0;i--){
	// 	for (int j=0;j<=x;j++){
	// 		int pick = 0;
	// 		if (h[i] <= j)
	// 			pick = next[j-h[i]] + s[i];
	// 		int dont_pick = next[j];
	// 		curr[j] = max(pick, dont_pick);
	// 	}
	// 	next = curr;
	// }
	// cout << next[x] << endl;

	// Iterative 1D DP
	vector<int> next(x+1, 0);
	for (int i = 0; i < n; i++) {
	    for (int j = x; j >= h[i]; j--) {
	    	next[j] = max(next[j], next[j-h[i]] + s[i]);
	    }
	}
	cout << next[x] << endl;
}