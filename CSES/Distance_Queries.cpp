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
vector<int> adjList[MAXN];
int h[MAXN];
int par[MAXN][18];
void DFS(int u) {
    for (int v : adjList[u]) {
        if (v == par[u][0]) continue;
        par[v][0] = u;
        for (int i = 1; i <= 17; i++) par[v][i] = par[par[v][i-1]][i-1];
        h[v] = h[u] + 1;
        DFS(v);
    }
}
int D(int u, int v) {
    if (h[u] < h[v]) swap(u,v);
    int k = h[u] - h[v];
    int kq = 0;
    for (int i = 17; i >= 0; i--) {
        if ((k >> i) & 1) u = par[u][i], kq += (1 << i);
    }
    if (u == v) return kq;
    for (int i = 17; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
            kq += 2 * (1 << i);
        }
    }
    kq = kq + 2;
    return kq;
}
void solve() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adjList[u].psb(v);
        adjList[v].psb(u);
    }
    h[1] = 0;
    DFS(1);
    while (q--) {
        int u, v; cin >> u >> v;
        cout << D(u,v) << endl;
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