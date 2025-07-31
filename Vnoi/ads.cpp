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
void DFS(int u, vector<bool> &visited, vector<vector<int>> adjList) {
    visited[u] = true;
    for (int v : adjList[u]) {
        if (visited[v]) continue;
        DFS(v,visited,adjList);
    }
}
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adjList(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adjList[u].psb(v);
        adjList[v].psb(u);
    }
    int scc_cnt = 0;
    vector<bool> visited(n,false);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        scc_cnt++;
        DFS(i,visited,adjList);
    }
    cout << m-n+scc_cnt;
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