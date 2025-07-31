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
const int MAXN = 3e4 + 1;
const string NoF = "Name_of_File";
vector<int> adjList[MAXN];
vector<int> path;
vector<int> visited(MAXN,-1);
int depth[MAXN];
int kq = 2;
void DFS(int u, int par) {
    visited[u] = 0;
    depth[u] = sz(path);
    path.psb(u);
    for (int v : adjList[u]) {
        if (visited[v] == 1 || v == par) continue;
        else if (visited[v] == 0) kq = max(kq,sz(path)-depth[v]);
        else DFS(v,u);
    }
    visited[u] = 1;
    path.ppb();
}
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adjList[u].psb(v);
        adjList[v].psb(u);
    }
    if (m == 0) {cout << 1; return;}
    for (int u = 0; u < n; u++) {
        if (visited[u] == 1) continue;
        DFS(u,-1);
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