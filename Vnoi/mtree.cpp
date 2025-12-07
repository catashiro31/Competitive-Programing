#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define psb push_back
#define int long long
vector<pair<int,int>> adj[100005];
vector<int> dp(100005,0);
int kq = 0;
void dfs(int u, int par) {
	for (auto [v,w] : adj[u]) {
		if (v == par) continue;
		dfs(v,u);
		kq = (kq + (1+dp[v])*w) % MOD;
		kq = (kq + (((1+dp[v])*w) % MOD) * dp[u]) % MOD;
		dp[u] = (dp[u] + (w * (1 + dp[v]))) % MOD;
	}
}

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n-1; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].psb({v,w});
		adj[v].psb({u,w});
	}
	dfs(1,0);
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	while(t--) solve();
}