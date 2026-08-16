// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;


int solve (int n,vector<int> &dp){
	if (n == 0)
		return 0;
	if (dp[n] != -1)
		return dp[n];

	int ans = 1e9, temp = n;
	while (temp > 0){
		int r = temp % 10;
		temp /= 10;
		if (r > 0){
			ans = min(ans, 1 + solve(n-r, dp));
		}
	}
	return dp[n] = ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; 
	cin >> n;
	// vector<int> dp(n+1,-1);
	// cout << solve (n,dp) << endl;

	vector<int> dp(n+1,1e9);
	dp[0] = 0;
	for (int i=1;i<=n;i++){
		int temp = i;
		while (temp > 0){
			int r =  temp % 10;
			temp /= 10;
			if (r > 0){
				dp[i] = min(dp[i], 1 + dp[i-r]);
			}
		}
	}
	cout << dp[n] << endl;
	return 0;
}