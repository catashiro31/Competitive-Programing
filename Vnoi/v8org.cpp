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
int K, kq = 0;
vector<int> adj[10005];
vector<int> dp(10005);
void dfs(int u, int par) {
	dp[u] = 1;
	for (int v : adj[u]) {
		if (v == par) continue;
		dfs(v,u);
		dp[u] += dp[v];
	}
	if (dp[u] >= K) kq++, dp[u] = 0; 
}

void solve() {
	cin >> K;
	int n; cin >> n;
	for (int i = 1; i <= n-1; i++) {
		int par; cin >> par;
		adj[i].psb(par-1);
		adj[par-1].psb(i);
	}
	dfs(0,-1);
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
