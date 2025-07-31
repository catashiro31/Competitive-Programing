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
    int n, q; cin >> n >> q;
    int prefix[n+1];
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) cin >> prefix[i];
    for (int i = 1; i <= n; i++) prefix[i] += prefix[i-1];
    vector<int> c(1e7+5,1);
    c[0] = 0, c[1] = 0;
    for (int i = 2; i*i < 1e7+5; i++) {
        if (!c[i]) continue;
        for (int j = i*i; j < 1e7+5; j+=i) c[j] = 0;
    }
    while (q--) {
        int u, v; cin >> u >> v;
        int sum = prefix[v] - prefix[u-1];
        if (sum < 0) cout << 0 << endl;
        else cout << c[sum] << endl;
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