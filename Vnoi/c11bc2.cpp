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
const int MAXN = 1e4;
const string NoF = "Name_of_File";
vector<pair<int,int>> adjList[MAXN];
int par[MAXN][15];
int val[MAXN][15];
int depth[MAXN];
void DFS(int u, int cpar) {
    for (auto [w,v] : adjList[u]) {
        if (v == cpar) continue;
        par[v][0] = u, val[v][0] = w, depth[v] = depth[u]+1;
        for (int i = 1; i < 15; i++) {
            par[v][i] = par[par[v][i-1]][i-1];
            val[v][i] = (val[v][i-1]|val[par[v][i-1]][i-1]);
        }
        DFS(v,u);
    }
}
int LCA(int u, int v) {
    int ans = 0;
    if (u == v) return ans;

    if (depth[u] < depth[v]) swap(u,v);
    int kc = depth[u] - depth[v];
    for (int i = 0; i < 15; i++) {
        if ((kc >> i) & 1) {
            ans |= val[u][i];
            u = par[u][i];
        }
    }

    if (u == v) return ans;

    for (int i = 14; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            ans |= val[u][i] | val[v][i];
            u = par[u][i];
            v = par[v][i];
        }
    }

    ans |= val[u][0] | val[v][0];
    return ans;
}

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int x, k; cin >> x >> k;
        adjList[i+1].psb({k-1,x-1});
        adjList[x-1].psb({k-1,i+1});
    }
    par[0][0] = 0; val[0][0] = 0, depth[0] = 0;
    DFS(0,-1);
    while(q--) {
        int x, y; cin >> x >> y;
        int kq = LCA(x-1,y-1);
        if (kq) cout << "YES" << endl;
        else cout << "NO" << endl;
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