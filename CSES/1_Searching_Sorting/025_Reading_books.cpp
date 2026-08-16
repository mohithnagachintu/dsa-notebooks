// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	ll s=0, maxi=-1, temp;
	for(int i=0;i<n;i++){
		cin >> temp;
		s += temp;
		if (temp > maxi)
			maxi = temp;
	}
	if (s > 2 * maxi)
		cout << s << endl;
	else cout << 2 * maxi << endl;
}