#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF LLONG_MAX
using ll = long long;
using namespace std;
int n, m;
void dijkstra(vector<pair<int,long>> adjList[]) {
	vector<ll> dst(n,INF);
	dst[0] = 0;
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
	pq.push({0,0});
	while (!pq.empty()) {
		ll d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (d > dst[u]) continue;
		for (auto x : adjList[u]) {
			int v = x.first;
			long w = x.second;
			if (dst[v] > dst[u]+w) {
				dst[v] = dst[u]+w;
				pq.push({dst[v],v});
			}
		}
	}
	for (int i = 0; i < n; i++) cout << dst[i] << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	vector<pair<int,long>> adjList[n];
	for (int i = 0; i < m; i++) {
		int u ,v; cin >> u >> v;
		long w; cin >> w;
		adjList[u-1].push_back({v-1,w});
	}
	dijkstra(adjList);
}
