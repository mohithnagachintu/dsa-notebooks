#include "bits_std_mac.h"
using namespace std;

using ll = long long;

ll solve(int pos, int prev, bool tight, bool started, string &s){
	if (pos == (int)s.size())
		return 1;

	ll ans = 0;
	int max_limit_pos = tight == true ? s[pos] - '0': 9;

	for (int d=0;d <= max_limit_pos;d++){
		if (started == true){
			if (d == prev)
				continue;
			if (tight == true && d == max_limit_pos){
				ans += solve(pos+1,d,true,true,s);
				// tight still applies
			} else {
				ans += solve(pos+1,d,false,true,s); 
				// release the tight condition for next digits
			}
		} else {
			if (d == 0){
				if (tight == true && d == max_limit_pos){
					ans += solve(pos+1,-1,true,false,s);
					// tight still applies
				} else {
					ans += solve(pos+1,-1,false,false,s); 
					// release the tight condition for next digits
				}
			} else {
				if (tight == true && d == max_limit_pos){
					ans += solve(pos+1,d,true,true,s);
					// tight still applies
				} else {
					ans += solve(pos+1,d,false,true,s); 
					// release the tight condition for next digits
				}
			}
		}
	}
	return ans;
}

ll count(int num){
	string s = to_string(num);
	ll ways = solve(0,-1,true,false,s);
	return ways;
}

// [a,b]
// count(b) - count(a-1)
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll a, b;
	cin >> a >> b;
	cout << count(b) - count(a-1) << endl;

}