#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void dfs(int u, const vector<vector<int>> &adj, int par, vector<vector<int>> &dp) {
	for (int v : adj[u]) {
		if (v == par) continue;
		dfs(v,adj,u,dp);
		dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1])) % MOD;
		dp[u][1] = (dp[u][1] * dp[v][0]) % MOD;
	}
}

void solve() {
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		--u , --v;
		adj[u].psb(v);
		adj[v].psb(u);
	}
	vector<vector<int>> dp(n,vector<int>(2,1));
	dfs(0,adj,-1,dp);
	cout << (dp[0][0] + dp[0][1]) % MOD << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
