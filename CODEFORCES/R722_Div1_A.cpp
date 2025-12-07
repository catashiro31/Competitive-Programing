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

void dfs(int u, int par, const vector<vector<int>> &adj, vector<vector<int>> &dp, const vector<pair<int,int>> &lr) {
	dp[u][0] = 0, dp[u][1] = 0;
	for (int v : adj[u]) {
		if (v == par) continue;
		dfs(v,u,adj,dp,lr);
		dp[u][0] += max(abs(lr[u].fi-lr[v].fi) + dp[v][0], abs(lr[u].fi-lr[v].se) + dp[v][1]);
		dp[u][1] += max(abs(lr[u].se-lr[v].fi) + dp[v][0], abs(lr[u].se-lr[v].se) + dp[v][1]);
	}
}

void solve() {
	int n; cin >> n;
	vector<pair<int,int>> lr(n);
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		lr[i] = {l,r};
	}
	vector<vector<int>> adj(n);
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].psb(v);
		adj[v].psb(u);
	}
	vector<vector<int>> dp(n,vector<int>(2,0));
	dfs(0,-1,adj,dp,lr);
	cout << max(dp[0][0], dp[0][1]) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
