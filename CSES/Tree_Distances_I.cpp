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
int mxd = 0, mxnode = 0;
void DFS(int u, int par, int d, vector<int> &c, const vector<vector<int>> &adjList) {
    c[u] = max(c[u],d);
    if (d > mxd) mxd = d, mxnode = u;
    for (int v : adjList[u]) {
        if (v == par) continue;
        DFS(v,u,d+1,c,adjList);
    }
}
void solve() {
    int n; cin >> n;
    vector<vector<int>> adjList(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        --u, --v; 
        adjList[u].psb(v);
        adjList[v].psb(u);
    }
    vector<int> c(n,0);
    DFS(0,-1,0,c,adjList);
    mxd = 0;
    DFS(mxnode,-1,0,c,adjList);
    mxd = 0;
    DFS(mxnode,-1,0,c,adjList);
    for (int x : c) cout << x << " ";
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