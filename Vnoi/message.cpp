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
int n, m, scc_cnt = 0; 
vector<int> adjList[1000], TadjList[1000];
vector<int> order;
bool visited[1000];
int scc_id[1000];

void DFS1(int u) {
    visited[u] = true;
    for (int v : adjList[u]) {
        if (!visited[v]) DFS1(v);
    }
    order.psb(u);
}

void DFS2(int u, int id) {
    scc_id[u] = id;
    visited[u] = true;
    for (int v : TadjList[u]) {
        if (!visited[v]) DFS2(v,id);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u,--v;
        adjList[u].psb(v);
        TadjList[v].psb(u);
    }

    memset(visited,false,sizeof(visited));
    for (int i = 0; i < n; i++) {
        if (!visited[i]) DFS1(i);
    }

    memset(visited,false,sizeof(visited));
    reverse(all(order));
    for (int u : order) {
        if (!visited[u]) {
            DFS2(u,scc_cnt);
            ++scc_cnt;
        }
    }

    vector<int> indeg(scc_cnt,0);
    for (int u = 0; u < n; u++) {
        for (int v : adjList[u]) {
            if (scc_id[u] != scc_id[v]) indeg[scc_id[v]]++;
        }
    }
    
    int kq = 0;
    for (int i = 0; i < scc_cnt; i++) if (indeg[i] == 0) kq++;
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