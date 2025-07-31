#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF LLONG_MAX
using ll = long long;
using namespace std;
void dijkstra(vector<vector<pair<int,int>>> adjList, int n) {
	vector<pair<ll,ll>> dist(n,{INF,0});
	dist[0] = {0,1};
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
	pq.push({0,0});
	while (!pq.empty()) {
		ll d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (d > dist[u].first) continue;
		for (auto [v,l] : adjList[u]) {
			if (dist[u].first + l < dist[v].first) {
				dist[v].first = dist[u].first + l;
				dist[v].second = dist[u].second;
				pq.push({dist[v].first,v});
			} else if (dist[u].first + l == dist[v].first) dist[v].second += dist[u].second;
		}
	}
	cout << dist[n-1].first << " " << dist[n-1].second;
}
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<pair<int,int>>> adjList(n);
	for (int i = 0; i < m; i++) {
		int k, u, v, l; cin >> k >> u >> v >> l;
		if (k == 2) {
			adjList[u-1].push_back({v-1,l});
			adjList[v-1].push_back({u-1,l});
		} else adjList[u-1].push_back({v-1,l});
	}
	dijkstra(adjList,n);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
