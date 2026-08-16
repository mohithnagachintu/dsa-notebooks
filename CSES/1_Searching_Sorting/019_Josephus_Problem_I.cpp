// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	deque<int> dq;
	for (int i=0;i<n;i++)
		dq.push_back(i+1);

	bool flag = false;
	int temp;
	while (!dq.empty()){
		temp = dq.front();
		dq.pop_front();
		if (!flag)
			dq.push_back(temp);
		else
			cout << temp << " ";
		flag = !flag;
	}
	return 0;
}