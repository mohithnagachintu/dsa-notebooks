// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<ll> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];


	// Monotonic Stack 
	stack<ll> st;

	for (int i=0;i<n;i++){
		while (!st.empty() && a[st.top()] >= a[i]){
			st.pop();
		}
		if (st.empty())
			cout << 0 << " ";
		else 
			cout << st.top() + 1 << " ";
		st.push(i);
	}
	return 0;
}