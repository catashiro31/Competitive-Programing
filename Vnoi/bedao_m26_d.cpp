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
int n, A, B;
void dfs(int u, int par, const vector<vector<pair<int,int>>> &adj, vector<vector<int>> &dp) {
	dp[u][0] = 0;
	dp[u][1] = 1e18, dp[u][2] = 1e18;
	for (auto [v,w] : adj[u]) {
		if (v == par) continue;
		dfs(v,u,adj,dp);
		dp[u][2] = min(dp[u][1] + min(dp[v][0], dp[v][1]) + min(A*w,B), dp[u][2] + min({dp[v][0],dp[v][1],dp[v][2]}) + B);
		dp[u][1] = min(dp[u][0] + min(dp[v][0], dp[v][1]) + min(A*w,B), dp[u][1] + min({dp[v][0],dp[v][1],dp[v][2]}) + B);
		dp[u][0] += min({dp[v][0], dp[v][1], dp[v][2]}) + B;
	}
}

void solve() {
	cin >> n >> A >> B;
	vector<vector<pair<int,int>>> adj(n);
	for (int i = 0; i < n-1; i++) {
		int u, v, w; cin >> u >> v >> w;
		--u, --v;
		adj[u].psb({v,w});
		adj[v].psb({u,w});
	}
	vector<vector<int>> dp(n,vector<int>(3));
	dfs(0,-1,adj,dp);
	cout << min({dp[0][0], dp[0][1], dp[0][2]}) + B;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
