#include "bits_std_mac.h"
// #include <bits/stdc++.h>
using namespace std;

string solve(int i,int j,int n, vector<vector<char>> &grid,
				vector<vector<string>> &dp,
				vector<vector<bool>> &vis
				){
	if (i==n-1 && j==n-1)
		return string(1, grid[i][j]);
	if (i==n || j==n)
		return "~";

	if (vis[i][j])
        return dp[i][j];
    vis[i][j] = true;

	string down = "~", right = "~";
	if (i+1 < n)
		down = solve(i + 1, j, n, grid,dp,vis);
	if (j+1<n)
		right = solve(i, j + 1, n, grid,dp,vis);
	dp[i][j] = grid[i][j] + min(down, right);
    return dp[i][j];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<char>> grid(n,vector<char>(n));

	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin >> grid[i][j];

	vector<vector<string>> dp(n, vector<string>(n));
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    cout << solve(0, 0, n, grid, dp, vis) << endl;

}