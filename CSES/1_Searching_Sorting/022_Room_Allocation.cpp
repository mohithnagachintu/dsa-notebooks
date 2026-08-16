// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

struct Range{
	int x,y,idx;
};

bool compare(const Range &a, const Range &b){
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<Range> a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i].x >> a[i].y;
		a[i].idx = i;
	}

	sort(a.begin(), a.end(),compare);

	// [end_time, room_id]
	priority_queue<pii,vector<pii>,greater<>> pq;

	int rooms = 0;
	vector<int> ans(n);
	for (int i=0;i<n;i++){
		if (!pq.empty() && pq.top().first < a[i].x){
			// reuse the same room
			int room_id = pq.top().second;
			pq.pop();
			pq.push({a[i].y, room_id});
			ans[a[i].idx] = room_id;
		} else{
			// new room
			rooms++;
			pq.push({a[i].y,rooms});
			ans[a[i].idx] = rooms;
		}
	}
	cout << rooms << endl;
	for (int i=0;i<n;i++)
		cout << ans[i] << " ";
}