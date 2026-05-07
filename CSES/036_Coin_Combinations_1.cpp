// #include "bits_std_mac.h"
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1000000007;

int solve(int n, int s, vector<int> &a, vector<int> &dp){
	if (s == 0) {
		return 1;
	}
	if (dp[s] != -1)
		return dp[s];
	int ans = 0;
	for (int i=0;i<n;i++){
		if (a[i] <= s){
			ans = (ans + solve(n,s-a[i],a,dp)) % MOD;
		}
	}
	return dp[s] = ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int n,s;
	cin >> n >> s;

	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];

	/* Memoization DP 
	vector<int> dp(s+1,-1);
	cout << solve(n,s,a,dp) << endl;
	*/

	vector<int> dp(s+1,0);
	dp[0] = 1;
	for (int j=1;j<=s;j++){
		for (int i=0;i<n;i++){
			if (a[i] <= j){
				// dp[j] = (dp[j] + dp[j-a[i]]) % MOD;
				// MOD is dangerous so use it properly
				dp[j] += dp[j-a[i]];
				if (dp[j] >= MOD)
					dp[j] -= MOD;
			}
		}
	}
	cout << dp[s] << endl;
}	