#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define pii pair<int,int>
#define pli pair<long,int>
#define plli pair<long long,int>
#define fi first
#define se second
#define INF LLONG_MAX
using ll = long long;
using namespace std;
void dijkstra(vector<vector<pli>> adjList, int n) {
	vector<pair<ll,int>> dist(n,{INF,INF});
	dist[0] = {0,1};
	priority_queue<plli, vector<plli>, greater<>> pq;
	pq.push({0,0});
	vector<int> par(n,-1);
	while (!pq.empty()) {
		ll d = pq.top().fi;
		int u = pq.top().se;
		pq.pop();
		if (d > dist[u].fi) continue;
		for (auto [v,w] : adjList[u]) {
			if (dist[u].fi + w < dist[v].fi) {
				dist[v].fi= dist[u].fi+w;
				dist[v].se = dist[u].se + 1;
				par[v] = u;
				pq.push({dist[v].fi,v});
			} else if (dist[u].fi + w == dist[v].fi && dist[u].se + 1 < dist[v].se) {
				dist[v].se = dist[u].se + 1;
				par[v] = u;
			}
		}
	}
	int z = n-1;
	cout << n - dist[z].se << endl;
	vector<bool> kq(n,true);
	kq[0] = false;
	while (par[z] != -1) {
		kq[z] = false;
		z = par[z];
	}
	for (int i = 0; i < n; i++) if (kq[i]) cout << i+1 << endl;
}
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<pli>> adjList(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		long w; cin >> w;
		--u, --v;
		adjList[u].push_back({v,w});
		adjList[v].push_back({u,w});
	}
	dijkstra(adjList,n);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
