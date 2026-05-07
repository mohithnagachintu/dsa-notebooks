#include "bits_std_mac.h"
using namespace std;

using ll = long long;
using pii = pair<int,int>;

bool comp(pii &a, pii &b){
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> pop(n);

	vector<pair<int,int>> a(n);
	string s;
	for (int i=0;i<n;i++){
		cin >> pop[i];
		a[i].first = pop[i];
		a[i].second = i;
	}
	cin >> s;
	sort(a.begin(), a.end(), comp);
	// for (auto &x:a)
	// 	cout << x.first << " " << x.second << endl;
	// cout << endl;

	int ans = 0;
	for (int i=0;i<n;i++){
		int idx = a[i].second, people = a[i].first;
		bool curr =  (s[idx] == '1');
		bool next = (idx + 1 < n && s[idx+1] == '1');

		if (!curr && !next)
			continue;
		else if (curr && !next){
			s[idx] = '0';
			ans += people;
			// cout << '[' << people << ',' << idx << "] -- " <<  "Using the guard at Idx: " << idx << endl;
		}
		else if (!curr && next){
			s[idx+1] = '0';
			ans += people;
			// cout << '[' << people << ',' << idx << "] -- " <<  "Using the guard at Idx: " << idx + 1 << endl;
		}
		else {
			// 11 case
			// cout << " Greedy Judging -- ";
			int idx_left = (idx > 0 ? pop[idx-1] : -1);
			int idx_right = (idx + 1 < n ? pop[idx+1] : -1);
			// cout << '{' << idx_left << ',' << idx_right << "} -- ";
			if (idx_left <= idx_right){
				// use your guard
				ans += people;
				s[idx] = '0';
				// cout << '[' << people << ',' << idx << "] -- " <<  "Using the guard at Idx: " << idx << endl;
			} else {
				// use next guard
				ans += people;
				s[idx+1] = '0';
				// cout << '[' << people << ',' << idx << "] -- "  <<  "Using the guard at Idx: " << idx + 1 << endl;
			}
		}
		// cout << '[' << i << ']' <<  s << endl;

	}	
	cout << ans << endl;
}


// Test cases:
// 6
// 20 10 9 30 20 19
// 011011

// 5
// 10 5 8 9 6
// 01101

// 4
// 5 4 5 1
// 0111

// 8
// 5 4 5 1 5 4 5 1 
// 01110111
