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
const int MAXN = 1e5 + 1;
const string NoF = "Name_of_File";
vector<pair<int,int>> adjList[MAXN];
int h[MAXN], par[MAXN][18];
int vmax[MAXN][18], vmin[MAXN][18];
void DFS(int u) {
    for (auto [v,w] : adjList[u]) {
        if (v == par[u][0]) continue;
        par[v][0] = u;
        vmax[v][0] = w, vmin[v][0] = w;
        for (int i = 1; i < 18; i++) {
            par[v][i] = par[par[v][i-1]][i-1];
            vmax[v][i] = max(vmax[v][i-1],vmax[par[v][i-1]][i-1]);
            vmin[v][i] = min(vmin[v][i-1],vmin[par[v][i-1]][i-1]);
        }
        h[v] = h[u] + 1;
        DFS(v);
    }
}
pair<int,int> Query(int u, int v) {
    if (h[u] < h[v]) swap(u,v);
    int k = h[u] - h[v];
    int cmin = INT_MAX, cmax = INT_MIN;
    for (int i = 17; i >= 0; i--) {
        if ((k>>i)&1) {
            cmin = min(cmin,vmin[u][i]);
            cmax = max(cmax,vmax[u][i]);
            u = par[u][i];
        }
    }
    if (u == v) return {cmin,cmax};
    for (int i = 17; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            cmin = min(cmin,vmin[u][i]);
            cmin = min(cmin,vmin[v][i]);
            cmax = max(cmax,vmax[u][i]);
            cmax = max(cmax,vmax[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }
    cmin = min(cmin,vmin[u][0]);
    cmin = min(cmin,vmin[v][0]);
    cmax = max(cmax,vmax[u][0]);
    cmax = max(cmax,vmax[v][0]);
    return {cmin, cmax};
}
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w;
        adjList[u].psb({v,w});
        adjList[v].psb({u,w});
    }
    h[1] = 0;
    DFS(1);
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        auto [kq1, kq2] = Query(u,v);
        cout << kq1 << " " << kq2 << endl;
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