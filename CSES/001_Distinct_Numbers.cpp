#include "bits_std_mac.h"
// #include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector <long long> a(n);
	for(int i=0;i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());

	int distinct = 0;
	for (int i=0;i<n;i++){
		if (i==0 || a[i] != a[i-1])
			distinct++;
	}
	cout << distinct << endl;
	return 0;
}


