#include "bits_std_mac.h"
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,a,b;
	cin >> n >> a >> b;
	vector<ll> arr(n);
	for(int i=0;i<n;i++)
		cin >> arr[i];

	ll s = 0, size = 0, ans = 0;
	for (int i=0;i<n;i++){
		s += arr[i];
		size++;
		if (s <= 0){
			s = 0;
			size = 0;
		}
		else if (size >= a && size <= b){
			if (s > ans) ans = s;
		}
		cout << "S = " << s << " Size = " << size << " Ans = " << ans << endl;
	}
	cout << ans << endl;
}