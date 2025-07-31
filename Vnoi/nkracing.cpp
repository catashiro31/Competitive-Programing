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
int par[MAXN];
int Find(int u) {
    if (u == par[u]) return u;
    return par[u] = Find(par[u]);
}
bool Union(int u, int v) {
    int pu = Find(u), pv = Find(v);
    if (pu == pv) return false;
    if (pu < pv) swap(pu,pv);
    par[pv] = pu;
    return true;
}
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) par[i] = i;
    priority_queue<pair<int,pair<int,int>>> pq;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        pq.push({w,{u,v}});
    }
    int kq = 0;
    while(!pq.empty()) {
        auto [w,uv] = pq.top(); pq.pop();
        auto [u,v] = uv;
        bool check = Union(u,v);
        if (!check) kq += w;
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