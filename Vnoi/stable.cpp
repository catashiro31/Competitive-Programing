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
void solve() {
	int n, m, s; cin >> n >> m >> s;
	set<pair<int,int>> edges;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		edges.insert({u,v});
	}
	for (auto [u,v] : edges) adj[u].psb(v);
	queue<int> q;
	q.push(--s);
	vector<int> dp(n,LLONG_MAX);
	vector<bool> sta(n,false);
	dp[s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (dp[v] == dp[u] + 1) sta[v] = true;
			else if (dp[v] > dp[u]+1) {
				dp[v] = dp[u]+1;
				sta[v] = sta[u];
				q.push(v);
			}
		}
	}
	int kq = 0;
	for (int i = 0; i < n; i++) kq += sta[i];
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
