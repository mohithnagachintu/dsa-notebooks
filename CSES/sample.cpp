#include <bits/stdc++.h>
// #include "bits_std_mac.h"
using namespace std;

int digitSum(int n) {
    stack<int> st;
    int sum = 0;

    while (n > 0) {
        st.push(n % 10);
        n /= 10;
    }

    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    int cnt = 0;
    for (int i = 1; ; i++) {
        if (digitSum(i) == 10) {
            cnt++;
            if (cnt == k) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}
