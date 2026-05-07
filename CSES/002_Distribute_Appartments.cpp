// #include "bits_std_mac.h"
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m,k,ans=0;
	cin >> n >> m >> k;
	vector <ll> app(n), av(m);

	for (int i=0;i<n;i++) cin >> app[i];
	for (int i=0;i<m;i++) cin >> av[i];

	sort(app.begin(), app.end());
	sort(av.begin(), av.end());


	int p1=0,p2=0;
		
	while (p1 < n && p2 < m){
		if (app[p1] < av[p2]-k){
			p1++;  // ignore this applicant
		} else if (app[p1] > av[p2] + k){
			p2++;  // ignore this appartment
		} else if (app[p1] >= av[p2] - k && app[p1] <= av[p2] + k){
			p1++;p2++;ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
