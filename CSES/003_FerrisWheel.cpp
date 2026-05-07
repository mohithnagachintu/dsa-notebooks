#include "bits_std_mac.h"
// #include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <algorithm>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    sort(a.begin(), a.end());
    
    int left = 0, right = n-1,ans=0;

    while (left <= right){
        if (a[left] + a[right] <= x){
            ans++;left++;right--;
        } else {
            ans++;right--;
        }
    }
    cout << ans << endl;
}