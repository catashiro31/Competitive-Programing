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
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> cmax(1e4+1,INT_MIN), cmin(1e4+1,INT_MAX);
    for (int i = 0; i < k; i++) {
        cmin[a[i]] = min(cmin[a[i]],i);
        cmax[a[i]] = max(cmax[a[i]],i);
    }
    int kq = 0;
    for (int i = 0; i <= 1e4; i++) {
        if (cmin[i] != INT_MAX && cmax[i] != INT_MIN) kq = max(kq,cmax[i]-cmin[i]);
    }
    cout << kq << " ";
    for (int i = 0; i <= n-k; i++) {
        if (cmin[a[i]] == i) cmin[a[i]] = INT_MAX;
        cmax[a[i]] = i;
        if (cmin[a[i]] != INT_MAX) kq = max(kq,)
    }
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