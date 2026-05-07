// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<long long, long long>;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	ll ip;
	ll temp = 0, maxi = LONG_MIN;
	for (int i=0;i<n;i++){
		cin >> ip;
		temp += ip;
		if (temp > maxi)
			maxi = temp;
		if (temp < 0)
			temp = 0;
	}
	cout << maxi << endl;
}