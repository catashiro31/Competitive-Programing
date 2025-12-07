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

void dfs(int u, int par, const vector<vector<int>> &adj, vector<vector<int>> &dp) {
	for (int v : adj[u]) {
		if (v == par) continue;
		dfs(v,u,adj,dp);
		dp[u][0] = (dp[u][0] * ((dp[v][1] + dp[v][2]) % MOD)) % MOD;
		dp[u][1] = (dp[u][1] * ((dp[v][0] + dp[v][2]) % MOD)) % MOD;
		dp[u][2] = (dp[u][2] * ((dp[v][0] + dp[v][1]) % MOD)) % MOD;
	}
}

void solve() {
	int n, k; cin >> n >> k;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].psb(v);
		adj[v].psb(u);
	}
	vector<int> color(n,0);
	for (int i = 0; i < k; i++) {
		int u, c; cin >> u >> c;
		color[--u] = c;
	}
	vector<vector<int>> dp(n,vector<int>(3));
	for (int i = 0; i < n; i++) {
		if (color[i] == 0) dp[i][0] = 1, dp[i][1] = 1, dp[i][2] = 1;
		else {
			for (int j = 1; j <= 3; j++) {
				if (j == color[i]) dp[i][j-1] = 1;
				else dp[i][j-1] = 0;
			}
		}
	}
	dfs(0,-1,adj,dp);
	cout << ((dp[0][0] + dp[0][1]) % MOD + dp[0][2]) % MOD;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("barnpainting.in","r",stdin);
	freopen("barnpainting.out","w",stdout);

	int t = 1;
	while(t--) solve();
}
