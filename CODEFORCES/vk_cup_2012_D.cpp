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
int kq = 0;

void dfs(int u, int par, const vector<vector<int>> &adj, vector<vector<int>> &dp, int k) {
	dp[u][0] = 1;
	for (int v : adj[u]) {
		if (v == par) continue;
		dfs(v,u,adj,dp,k);
		for (int i = 0; i < k; i++) {
			kq += dp[u][i] * dp[v][k-i-1];
		}
		for (int i = 0; i < k; i++) dp[u][i+1] += dp[v][i];
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
	vector<vector<int>> dp(n,vector<int>(k+1,0));
	dfs(0,-1,adj,dp,k);
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
