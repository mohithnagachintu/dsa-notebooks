// #include "bits_std_mac.h"
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int swap_pos(vector<int> &a, vector<int> &pos, int x, int y){


}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;

	vector<int> a(n),pos(n+1);
	for(int i=0;i<n;i++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	vector<vector<int>> swap(m);
	int a,b;
	for (int i=0;i<m;i++){
		cin >> a >> b;
		swap.push_back({a-1,b-1});
	}

	ll rounds = 1;
	for (int i=2;i<=n;i++){
		if (pos[i] < pos[i-1])
			rounds++;
	}
	
	for (int i=0;i<m;i++){
		rounds += swap_pos(a,pos,swap[i][0],swap[i][1]);
		cout << rounds << endl;
	}



}