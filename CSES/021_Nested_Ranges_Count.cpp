// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

struct Range{
	int x,y,idx;
};

bool compare(const Range &a, const Range &b){
	if (a.x == b.x)
		return a.y > b.y;
	return a.x < b.x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a1(n,false), a2(n,false);


	vector<Range> ranges(n);
	for(int i=0;i<n;i++){
		cin >> ranges[i].x >> ranges[i].y;
		ranges[i].idx = i;
	}
	sort(ranges.begin(), ranges.end(), compare);

	
	multiset<int> st;

	for (int i=n-1;i>=0;i--){
		Range r = ranges[i];
		auto it = st.upper_bound(r.y);
		a1[r.idx] = distance(st.begin(), it);
		// if (it != st.begin())
		// 	a1[r.idx] = true;
		st.insert(r.y);
	}
	st.clear();

	for (int i=0;i<n;i++){
		Range r = ranges[i];
		auto it = st.lower_bound(r.y);
		a2[r.idx] = distance(it, st.end());
		// if (it != st.end())d
		// 	a2[r.idx] = true;
		st.insert(r.y);
	}

	for(int i=0;i<n;i++)
		cout << a1[i] << " ";
	cout << endl;
	for(int i=0;i<n;i++)
		cout << a2[i] << " ";
}