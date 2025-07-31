#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF INT_MAX
using ll = long long;
using namespace std;
int n, m, q, src;
void dijkstra(vector<pair<int,int>> adjList[], int src, vector<int> &dst) {
	dst[src] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,src});
	while (!pq.empty()) {
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (d > dst[u]) continue;
		for (auto x : adjList[u]) {
			int v = x.first;
			int w = x.second;
			if (dst[v] > dst[u]+w) {
				dst[v] = dst[u] + w;
				pq.push({dst[v],v});
			}
		}
	} 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	do {
		cin >> n >> m >> q >> src;
		if (!n && !m && !q && !src) break;
		vector<pair<int,int>> adjList[n];
		for (int i = 0; i < m; i++) {
			int u, v, w; cin >> u >> v >> w;
			adjList[u].push_back({v,w});
		}
		vector<int> dst(n, INF);
		dijkstra(adjList,src,dst);
		while(q--) {
			int x; cin >> x;
			if (dst[x] == INF) cout << "Impossible" << endl;
			else cout << dst[x] << endl;
		}
		cout << endl;
	} while (true);
}
