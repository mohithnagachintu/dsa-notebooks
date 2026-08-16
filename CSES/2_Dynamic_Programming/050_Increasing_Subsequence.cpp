// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Recursion + Memo
// int solve(int i,int prev, int n, vector<int> &a,vector<vector<int>> &dp){
// 	// base case
// 	if (i == n){
// 		return 0;
// 	}
// 	// dp check
// 	if (dp[i][prev+1] != -1){
// 		return dp[i][prev+1];
// 	}
// 	// choices
// 	int dont_pick = solve(i+1,prev,n,a,dp);
// 	int pick = 0;
// 	if (a[i] > a[prev]){
// 		pick = solve(i+1,i,n,a,dp) + 1;
// 	}
// 	return dp[i][prev+1] = max(dont_pick,pick);
// }

void print(vector<int> &nums){
	for (int i=0;i<nums.size();i++){
		cout << nums[i] << " ";
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	// TLE - Recursion + TLE
	// vector<vector<int>> dp(n,vector<int>(n,-1));
	// cout << solve(0,-1,n,a,dp) << endl;

	// TLE - Iterative DP - 2x10**5 length array
	// vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	// for (int i = n - 1; i >= 0; i--) {
	//     for (int prev = i - 1; prev >= -1; prev--) {
	//         int dont_pick = dp[i + 1][prev + 1];
	//         int pick = 0;
	//         if (prev == -1 || a[i] > a[prev]) {
	//             pick = 1 + dp[i + 1][i + 1];
	//         }
	//         dp[i][prev + 1] = max(dont_pick, pick);
	//     }
	// }
	// cout << dp[0][0] << endl;

	// Optimal Algorithm - Patience Sorting
	vector<int> temp = {a[0]};

	for (int i=1;i<n;i++){
		if (a[i] > temp.back()){
			temp.push_back(a[i]);
		} else {
			int idx = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
			temp[idx] = a[i];
		}
		// print(temp);
	}
	cout << temp.size() << endl;

	
}