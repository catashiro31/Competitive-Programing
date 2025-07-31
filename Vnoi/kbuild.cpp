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
vector<int> adjList[MAXN];
int cur[MAXN], par[MAXN];
int BFS(int u, int dest) {
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == dest) {
            int ans = 0;
            while (u != par[u]) {
                if (u != dest) {
                    for (int v : adjList[u]) {
                        if (cur[v] == dest && cur[v] != par[u]) continue;
                        adjList[dest].psb(cur[v]);
                        adjList[cur[v]].psb(dest); 
                    }
                }
                u = par[u];
                cur[u] = dest;
                ans++;
            }
            return ans;
        }
        for (int v : adjList[u]) {
            if (cur[v] == par[u]) continue;
            par[cur[v]] = u;
            q.push(cur[v]);
        }
    }
}
int processing(int u, int v) {
    if (cur[u] == cur[v]) return 0;
    return DFS(cur[u],cur[v]);
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cur[i] = i;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adjList[u].psb(v);
        adjList[v].psb(u);
    }
    int m; cin >> m;
    int kq = n-1;
    while (m--) {
        int u, v; cin >> u >> v;
        kq -= processing(u,v);
    }
    // cout << kq;
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