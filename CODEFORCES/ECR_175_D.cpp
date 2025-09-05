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
const int MOD = 998244353;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";
void dfs(int u, int par, const vector<int> adjList[], vector<int> &depth) {
    for (int v : adjList[u]) {
        if (v == par) continue;
        depth[v] = depth[u]+1;
        dfs(v, u, adjList, depth);
    }
}
void solve() {
    int n; cin >> n;
    vector<int> adjList[n];
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        adjList[i].psb(x-1);
        adjList[x-1].psb(i);
    }
    vector<int> depth(n,0);
    depth[0] = 0;
    dfs(0, -1, adjList, depth);
    vector<ll> dp(n,0), sl(n,0);
    vector<bool> visited(n,false);
    dp[0] = 1; sl[depth[0]] = (sl[depth[0]] + 1) % MOD;
    visited[0] = true;
    queue<int> q;
    for (int v : adjList[0]) {
        dp[v] = 1; sl[depth[v]] = (sl[depth[v]] + dp[v]) % MOD;
        visited[v] = true;
        q.push(v);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        visited[u] = true;
        for (int v : adjList[u]) {
            if (visited[v]) continue;
            dp[v] = ((sl[depth[u]] - dp[u]) % MOD + MOD) % MOD;
            sl[depth[v]] = (sl[depth[v]] + dp[v]) % MOD;
            q.push(v);
        }
    }
    ll kq = 0;
    for (int u = 0; u < n; u++) kq = (kq + dp[u]) % MOD;
    cout << kq << endl;
}
    
int main() {
#ifndef ONLINE_JUDGE
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
}