// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	int n,k;
// 	cin >> n >> k;
// 	deque<int> dq;

// 	for(int i=0;i<n;i++)
// 		dq.push_back(i+1);

// 	while (!dq.empty()){
// 		int size = dq.size();
// 		int _k = k % size;
// 		// skip k items
// 		for (int i=0;i<_k;i++){
// 			int temp = dq.front();
// 			dq.push_back(temp);
// 			dq.pop_front();
// 		}
// 		cout << dq.front() << " ";
// 		dq.pop_front();
// 	}
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k) {
    int survivor = 0; // Base case: J(1, k) = 0 in 0-based indexing

    for (int i = 2; i <= n; i++) {
        survivor = (survivor + k) % i; // Compute survivor iteratively
    }

    return survivor + 1; // Convert 0-based index to 1-based
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << josephus(n, k) << endl;
    return 0;
}
