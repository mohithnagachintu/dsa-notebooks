// #include "bits_std_mac.h"
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n),pos(n+1);
	for(int i=0;i<n;i++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	ll rounds = 1;
	for (int i=2;i<=n;i++){
		if (pos[i] < pos[i-1])
			rounds++;
	}
	cout << rounds << endl;
}