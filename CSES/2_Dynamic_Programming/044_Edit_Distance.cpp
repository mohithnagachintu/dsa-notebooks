// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;


// make s1 like s2
int solve (int i,int j,int n,int m, string &s1,string &s2,vector<vector<int>> &dp){
	// base case
	if (i==n)
		return m - j;
	if (j==m)
		return n - i;

	if (dp[i][j] != -1)
		return dp[i][j];

	int ans = 0;
	if (s1[i] == s2[j]){
		ans = solve(i+1,j+1,n,m,s1,s2,dp);
	}
	else {
		int ins = 1 + solve(i,j+1,n,m,s1,s2,dp); // insert s2[j] at i
		int del = 1 + solve(i+1,j,n,m,s1,s2,dp); //d delete s2[j];
		int rep = 1 + solve(i+1,j+1,n,m,s1,s2,dp);
		ans = min({ins,del,rep});
	}
	
	return ans;
}	


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size(), m = s2.size();
	// vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
	// cout << solve(0,0,n,m,s1,s2,dp) << endl;

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int j = 0; j <= m; j++)
        dp[n][j] = m - j;

    for (int i = 0; i <= n; i++)
        dp[i][m] = n - i;
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i + 1][j + 1];
            } else {
                dp[i][j] = 1 + min({
                    dp[i][j + 1],     // insert
                    dp[i + 1][j],     // delete
                    dp[i + 1][j + 1]  // replace
                });
            }
        }
    }

    cout << dp[0][0] << "\n";

	return 0;
}