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
vector<vector<int>> adjList(MAXN); 
vector<int> id(MAXN,0), low(MAXN,0);
int bridge = 0, articulation = 0, cnt = 0;
void DFS(int u, int p) {
    id[u] = low[u] = ++cnt;
    int node = (p != -1);
    for (int v : adjList[u]) {
        if (v == p) continue;
        if (id[v]) low[u] = min(low[u],id[v]);
        else {
            DFS(v,u);
            low[u] = min(low[u],low[v]);
            if (low[v] == id[v]) bridge++;
            if (low[v] >= id[u]) node++;
        }
    }
    if (node >= 2) articulation++;
}
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adjList[u].psb(v);
        adjList[v].psb(u);
    }
    for (int i = 0; i < n; i++) {
        if (id[i]) continue;
        DFS(i,-1);
    }
    cout << articulation << " " << bridge;
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