// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// int solve(int i, int j, int n, vector<vector<char>> &grid,vector<vector<int>> &dp){
// 	if (i >= n || j >= n || grid[i][j] == '*')
// 		return 0;
// 	if (i == n-1 && j == n-1)
// 		return 1;
// 	if (dp[i][j] != -1)
// 		return dp[i][j];
// 	int ways = 0;
// 	int di[2] = {1,0}, dj[2] = {0,1};
// 	for (int d=0;d<2;d++){
// 		ways += solve(i + di[d], j + dj[d], n, grid,dp);
// 		if (ways >= MOD)
// 			ways -= MOD;
// 	}
// 	return dp[i][j] = ways;
// }

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<char>> grid(n,vector<char>(n));
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> grid[i][j];
		}
	}
	// vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	// cout << solve(0,0,n,grid,dp) << endl;

	vector<vector<int>> dp(n,vector<int>(n,0));
	if (grid[n-1][n-1] == '*')
	    dp[n-1][n-1] = 0;
	else
	    dp[n-1][n-1] = 1;
	int di[2] = {1,0}, dj[2] = {0,1};

	for (int i=n-1;i>=0;i--){
		for (int j=n-1;j>=0;j--){
			if (i==n-1 && j==n-1)
				continue;
			if (grid[i][j] != '*'){
				int ways = 0;
				for (int d=0;d<2;d++){
					ways += solve(i + di[d], j + dj[d], n, grid,dp);
					if (ways >= MOD)
						ways -= MOD;
				}
				dp[i][j] = ways;
			}
		}
	}
	cout << dp[0][0] << endl;
	return 0;
}