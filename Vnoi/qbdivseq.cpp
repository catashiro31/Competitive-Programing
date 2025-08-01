#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    vector<int> store;
    for (int x : arr) {
        auto it = lower_bound(store.begin(),store.end(),x, greater<>());
        if (it == store.end()) store.push_back(x);
        else *it = x;
    }
    cout << store.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
