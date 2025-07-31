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
const int MAXN = 7e5 + 1;
const string NoF = "Name_of_File";
vector<int> adjList[MAXN];
vector<vector<int>> par(MAXN, vector<int>(20,0));
vector<int> depth(MAXN,0);
int segtree[4*MAXN];
void dfs(int u, int prv) {
    for (int v : adjList[u]) {
        if (v == prv) continue;
        par[v][0] = u;
        depth[v] = depth[u]+1;
        for (int i = 1; i < 20; i++) {
            par[v][i] = par[par[v][i-1]][i-1];
        }
        dfs(v,u);
    }
}
int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u,v);
    int kc = depth[u] - depth[v];
    for (int i = 0; i < 20; i++) {
        if ((kc >> i)&1) u = par[u][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
void build_segtree(int id, int l, int r) {
    if (l == r) {
        segtree[id] = l;
        return;
    }
    int m = (l+r)/2;
    build_segtree(id*2,l,m);
    build_segtree(id*2+1,m+1,r);
    segtree[id] = get_lca(segtree[id*2],segtree[id*2+1]);
}
int query_segtree(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) return segtree[id];
    int m = (l+r)/2;
    int nodel = query_segtree(id*2,l,m,u,v);
    int noder = query_segtree(id*2+1,m+1,r,u,v);
    if (nodel == 0 || noder == 0) return nodel+noder;
    return get_lca(nodel, noder);
}
void solve() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adjList[u].psb(v);
        adjList[v].psb(u);
    }
    par[1][0] = 0;
    dfs(1,0);
    build_segtree(1,1,n);
    while (q--) {
        int u, v; cin >> u >> v;
        cout << query_segtree(1,1,n,u,v) << endl;
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