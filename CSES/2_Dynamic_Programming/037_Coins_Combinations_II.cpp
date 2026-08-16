// #include "bits_std_mac.h"
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1000000007;

int solve(int i,int n, int s, vector<int> &a,vector<vector<int>> &dp){
	if (s==0)
		return 1;
	if (i == n) {
		return 0;
	}

	if (dp[i][s] != -1)
		return dp[i][s];

	int pick = 0;
	if (a[i] <= s)
		pick = solve(i,n,s-a[i],a,dp);
	int dont_pick = solve(i+1,n,s,a,dp);
	int ans = 0;
	if (pick + dont_pick >= MOD)
		ans = pick + dont_pick - MOD;
	else
		ans = pick + dont_pick;
	return dp[i][s] = ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int n,s;
	cin >> n >> s;

	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];


	/* Memoization 2D DP 
	vector<vector<int>> dp(n,vector<int>(s+1,-1));
	cout << solve(0,n,s,a,dp) << endl;
	*/

	vector<vector<int>> dp(n+1,vector<int>(s+1,0));
	for (int i=0;i<=n;i++)
		dp[i][0] = 1;

	for (int i=n-1;i>=0;i--){
		for (int j=1;j<=s;j++){
			int pick = 0;
			if (a[i] <= j){
				pick = dp[i][j-a[i]];
			}
			int dont_pick = dp[i+1][j],ans;
			if (pick + dont_pick >= MOD)
				ans = pick + dont_pick - MOD;
			else
				ans = pick + dont_pick;
			dp[i][j] = ans;
		}
	}
	cout << dp[0][s] << endl;
}	