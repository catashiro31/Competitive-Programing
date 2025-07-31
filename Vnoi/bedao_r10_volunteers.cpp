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
int par[MAXN];
int Find(int u) {
    if (par[u] == u) return u;
    return par[u] = Find(par[u]);
}
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i <= n; i++) par[i] = i;
    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    sort(all(a));
    for (int x : b) {
        int u = ub(all(a),x) - a.begin();
        if (!u) continue;
        int v = Find(u);
        if (!v) continue;
        par[v] = Find(v-1);
    }
    int kq = INT_MIN;
    for (int u = 0; u < n; u++) {
        int v = Find(u+1);
        if (!v) continue;
        kq = max(kq,a[par[v]-1]);
    }
    if (kq == INT_MIN) cout << -1;
    else cout << kq;
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