#include<bits/stdc++.h>
using namespace std;

#define psb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define int long long

const int INF = 1e15;

void dfs(int u, int par, const vector<vector<pair<int,int>>> &adj, vector<vector<int>> &dp, vector<int> &d) {
    vector<int> dif;
    int base_sum = 0;
    
    for (auto [v,w] : adj[u]) {
        if (v == par) continue;
        dfs(v, u, adj, dp, d);
        base_sum += dp[v][0];
        dif.psb(w + dp[v][1] - dp[v][0]);
    }
    
    sort(all(dif), greater<int>());
    int z = sz(dif);

    if (d[u] == 0) {
        dp[u][1] = -INF; 
    } else {
        int sum = base_sum;
        for (int i = 0; i < min(z, d[u]-1); i++) {
            if (dif[i] > 0) sum += dif[i];
            else break;
        }
        dp[u][1] = sum;
    }

    int sum = base_sum;
    for (int i = 0; i < min(z, d[u]); i++) {
        if (dif[i] > 0) sum += dif[i];
        else break;
    }
    dp[u][0] = sum;
}

void solve() {
    int n; cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        adj[u].psb({v,w});
        adj[v].psb({u,w});
    }
    
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dfs(0, -1, adj, dp, d);
    cout << dp[0][0];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) solve();
}