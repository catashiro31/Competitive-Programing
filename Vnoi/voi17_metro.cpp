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
	int n, m, src, dst, thera; cin >> n >> m >> src >> dst >> thera;
	vector<vector<tuple<int,int,int>>> adj(n+1);
	for (int i = 1; i <= m; i++) {
		int u, v, t; cin >> u >> v >> t;
		adj[u].psb({v,t,i});
	}
	vector<pair<int,int>> dist(n+1,{LLONG_MAX,LLONG_MAX});
	dist[src] = {0,-1};
	priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> pq;
	pq.push({{0,-1},src});
	while(!pq.empty()) {
		auto [dprv,u] = pq.top(); pq.pop();
		auto [d,prv] = dprv;
		if (dprv > dist[u]) continue;
		for (auto [v,t,now] : adj[u]) {
			pair<int,int> dif = {dist[u].fi + t, now};
			if (prv != -1) dif.fi += prv * thera + now;
			if (dist[v] > dif) {
				dist[v] = dif;
				pq.push({dist[v],v});
			}
		}
	}
	if (dist[dst].fi != LLONG_MAX) cout << dist[dst].fi << endl;
	else cout << -1 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}