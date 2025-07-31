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
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";
    
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x <= k ? 1:-1;
    }
    vector<int> lprefix(n), rprefix(n);
    lprefix[0] = a[0], rprefix[n-1] = a[n-1];
    for (int i = 1; i < n; i++) lprefix[i] = lprefix[i-1]+a[i];
    for (int i = n-2; i >= 0; i--) rprefix[i] = rprefix[i+1]+a[i];
    bool kq = false;
    bool c = false;
    for (int i = 1; i < n-1; i++) {
        if (c) kq = true;
        c = ((lprefix[i] == 0) || c);
    }
    if (kq) {
        cout << "YES" << endl;
        return;
    }
    for (int i = n-2; i > 0; i--) {
        if (c) kq = true;
        c = ((rprefix[i] == 0) || c);
    }
    if (kq) {
        cout << "YES" << endl;
        return;
    }
    for () {

    }
    if (kq) cout << "YES" << endl;
    else cout << "NO" << endl;
}
    
int main() {
#ifndef ONLINE_JUDGE
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
}