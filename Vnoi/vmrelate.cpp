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
    
void solve() {
    int n, m; cin >> n >> m;
    vector<int> adjList[n];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adjList[u].psb(v);
        adjList[v].psb(u);
    }

    vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
    for (int i = 0; i < n; i++) {
        queue<int> q; q.push(i);
        dp[i][i] = 0;
        vector<bool> c(n,false);
        c[i] = true;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adjList[u]) {
                if (c[v]) continue;
                dp[i][v] = dp[i][u] + 1;
                c[v] = true;
                q.push(v);
            }
        }
    }
    int kq = INT_MAX;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = i; k <= j; k++) {
                if (dp[i][j] != 1 || dp[i][k] == INT_MAX || dp[k][j] == INT_MAX) continue;
                if (kq > abs(dp[i][k]-dp[k][j])) l = i, r = j, kq = abs(dp[i][k]-dp[k][j]);
            }
        }
    }
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