#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

struct edge{
	int u, v, w;
};

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<pair<int,int>>> adj(n);
	vector<edge> road;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		--u, --v;
		road.psb({u,v,w});
		adj[u].psb({v,w});
		adj[v].psb({u,w});
	}
	vector<edge> train;
	for (int i = 0; i < k; i++) {
		int s, y; cin >> s >> y;
		--s;
		train.psb({0,s,y});
		train.psb({s,0,y});
		adj[0].psb({s,y});
		adj[s].psb({0,y});
	}
	vector<int> dist(n,LLONG_MAX);
	dist[0] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,0});
	while (!pq.empty()) {
		auto [d,u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;
		for (auto [v,w] : adj[u]) {
			if (dist[u] + w >= dist[v]) continue;
			dist[v] = dist[u] + w;
			pq.push({dist[v],v});
		}
	}
	vector<int> ingree(n, 0);
	for (auto e : road) {
	    if (dist[e.u] != LLONG_MAX && dist[e.u] + e.w == dist[e.v]) {
	        ingree[e.v]++;
	    }
	    if (dist[e.v] != LLONG_MAX && dist[e.v] + e.w == dist[e.u]) {
	        ingree[e.u]++;
	    }
	}
	for (auto e : train) {
	    if (dist[e.u] != LLONG_MAX && dist[e.u] + e.w == dist[e.v]) {
	        ingree[e.v]++;
	    }
	}
	int kq = 0;
	for (auto e : train) {
		int s = e.v, y = e.w;
		if (s == 0) continue;
		if (y > dist[s]) kq++;
		else if (y == dist[s]) {
			if (ingree[s] > 1) kq++, ingree[s]--;
		}
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
