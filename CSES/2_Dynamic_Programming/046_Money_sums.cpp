// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;


void solve(int i,int n,int s,vector<bool> &sum_bool,vector<int> &a, vector<vector<int>> &dp){
	sum_bool[s] = true;
	if (i==n){
		return;
	}
	if (dp[i][s] != -1){
		// already computed this path
		return;
	}
	solve(i+1,n,s,sum_bool,a,dp);
	solve(i+1,n,s+a[i],sum_bool,a,dp);
	dp[i][s] = 1; // tried this combo
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	int s = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		s += a[i];
	}
	sort(a.begin(), a.end());
	vector<bool> sum_bool(s+1,false);

	// Recursion + Memoization 2D DP
	// vector<vector<int>> dp(n+1,vector<int>(s+1,-1));
	// solve(0,n,0,sum_bool,a,dp);
	// vector<int> ans;
	// for (int i=1;i<=s;i++)
	// 	if (sum_bool[i])
	// 		ans.push_back(i);
	// cout << ans.size() << endl;
	// for (int i=0;i<ans.size();i++)
	// 	cout << ans[i] << " ";


	// Iterative 2D DP
	// vector<vector<int>> dp(n+1,vector<int>(s+1,0));
	// dp[n][0] = 1; 
	// for (int i=n-1;i>=0;i--){
	// 	for (int j=s;j>=0;j--){
	// 		if (dp[i+1][j] == 0)
	// 			continue;
	// 		// skip the coin
	// 		dp[i][j] = 1;
	// 		// take the coin
	// 		if (j+a[i] <= s)
	// 			dp[i][j+a[i]] = 1;
	// 	}
	// }
	// vector<int> ans;
    // for (int j = 1; j <= s; j++)
    //     if (dp[0][j])
    //         ans.push_back(j);
    // cout << ans.size() << '\n';
    // for (int x : ans)
    //     cout << x << " ";

	// Space Optimized 1D DP
	vector<int> dp(s+1,0);
	dp[0] = 1;
	for (int i=n-1;i>=0;i--){
		for (int j=s;j>=0;j--){
			if (dp[j] == 0)
				continue;
			dp[j] = 1;
			if (j+a[i] <= s)
				dp[j+a[i]] = 1;
		}
	}
	vector<int> ans;
    for (int j = 1; j <= s; j++)
        if (dp[j])
            ans.push_back(j);
    cout << ans.size() << '\n';
    for (int x : ans)
        cout << x << " ";
}