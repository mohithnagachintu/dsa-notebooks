// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int solve(int i,int j,int n, vector<int> &a,vector<vector<int>> &dp){
	if (i > j)
		return 0;
	if (i==j)
		return a[i];

	if (dp[i][j] != -1)
		return dp[i][j];

	// case 1: 1st picked i, 2nd picked j
	int c1 = a[i] + solve(i+1,j-1,n,a,dp);
	// case 2: 1st picked i, 2nd picked i+1
	int c2 = a[i] + solve(i+2,j,n,a,dp);
	// case 3: 1st picked j, 2nd picked i
	int c3 = a[j] + solve(i+1,j-1,n,a,dp); 
	// case 4: 1st picked j, 2nd picked j-1
	int c4 = a[j] + solve(i,j-2,n,a,dp);
	
	// Given that, both players should play optimally
    // Opponent chooses the worse outcome for us, 
    // it is trying to minimize the score of first person
    int pickLeft  = min(c1, c2);  // desperate
   	int pickRight = min(c3, c4);  // desperate

    return max(pickLeft, pickRight);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];


	// Recurison + Memoization - TLE
	// vector<vector<int>> dp(n,vector<int>(n,-1));
	// cout << solve(0,n-1,n,a,dp) << endl;

	vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
	for (int i=0;i<n;i++)
		dp[i][i] = a[i];

	for (int i=n-1;i>=0;i--){
		for (int j=i+1;j<=n-1;j++){
			// case 1: 1st picked i, 2nd picked j
			ll c1 = a[i] + dp[i+1][j-1];
			// case 2: 1st picked i, 2nd picked i+1
			ll c2 = a[i] + dp[i+2][j];
			// case 3: 1st picked j, 2nd picked i
			ll c3 = a[j] + dp[i+1][j-1];
			// case 4: 1st picked j, 2nd picked j+1
			ll c4 = a[j] + dp[i][j-2];
			
			// Given that, both players should play optimally

		    // Opponent chooses the worse outcome for us, 
		    // it is trying to minimize the score of first person
		    ll pickLeft  = min(c1, c2);
		   	ll pickRight = min(c3, c4);
		   	dp[i][j] = max(pickLeft, pickRight);
		}
	}
	cout << dp[0][n-1] << endl;
}