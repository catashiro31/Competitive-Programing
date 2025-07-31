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
void Union(int u, int v) {
    int pu = Find(u), pv = Find(v);
    if (pu == pv) return;
    if (pu < pv) par[pv] = pu;
    else par[pu] = pv;
}
void solve() {
    int p; cin >> p;
    for (int i = 0; i < MAXN; i++) par[i] = i;
    while (p--) {
        int x, y, t; cin >> x >> y >> t;
        if (t == 1) Union(x,y);
        else cout << (Find(x) == Find(y)) << endl;
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