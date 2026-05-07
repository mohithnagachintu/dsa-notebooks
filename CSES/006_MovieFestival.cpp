// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<long long, long long>;

bool comp(const pll &a, const pll &b){
	return a.second < b.second;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pll> a(n);
	for (int i=0;i<n;i++)
		cin >> a[i].first >> a[i].second;

	// sort by ending values
	sort(a.begin(), a.end(), comp);

	int end = -1, overlap=0;
	for (auto &i:a){
		if (i.first >= end){
			end = i.second;
		} else {
			overlap++;
		}
	}
	cout << n - overlap << endl;

}