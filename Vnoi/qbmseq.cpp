#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define psb push_back
#define ppb pop_back
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";
void solve() {
    int n; cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; arr.psb(x);
    }
    vector<bool> c(n,false);
    for (int i = 0; i < n; i++) {
        int a = sqrt(arr[i]*2);
        if (a*(a+1) == arr[i]*2 || a*(a-1) == arr[i]*2) c[i] = true;
    }
    int kq = 0, cnt = c[0] ? 1 : 0;
    for (int i = 1; i < n; i++) {
        if (arr[i-1] <= arr[i] && c[i-1] && c[i]) cnt++, kq = max(kq,cnt);
        else {
            if (c[i]) cnt = 1;
            else cnt = 0;
        }
    }
    cout << kq;
}
    
int main() {
#ifndef ONLINE_JUDGE
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}