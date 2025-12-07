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
	int n, m; cin >> n >> m;
	int src, dst; cin >> src >> dst;
	vector<vector<pair<int,int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, d; cin >> u >> v >> d;
		--u, --v;
		adj[u].psb({v,d});
	}
	--src, --dst;
	priority_queue<pair<int,int>> pq;
	pq.push({0,src});
	vector<int> dist(n,LLONG_MAX);
	dist[src] = 0;
	while(!pq.empty()) {
		auto [d,u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;
		for (auto [v, d] : adj[u]) {
			if (dist[v] > dist[u] + d) {
				dist[v] = dist[u]+d;
				pq.push({dist[v],v});
			}
		}
	}
	if (dist[dst] == LLONG_MAX) cout << -1 << endl;
	else cout << dist[dst] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
