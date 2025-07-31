#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF INT_MAX
using ll = long long;
using namespace std;
int n, m, q, src; 
struct edge {
	int u, v, w;
};
void BellmanFord(vector<edge> Edge, int src, vector<int> &dst) {
	dst[src] = 0;
	for (int i = 0; i < n-1; i++) {
		for (auto e : Edge) {
			int u = e.u, v = e.v, w = e.w;
			if (dst[u] != INF && dst[v] > dst[u] + w) dst[v] = dst[u] + w;
		}
	}
	for (int i = 0; i < n-1; i++) {
		for (auto e : Edge) {
			int u = e.u, v = e.v, w = e.w;
			if (dst[u] == -INF) dst[v] = -INF;
			else if (dst[u] != INF && dst[v] > dst[u] + w) dst[v] = -INF;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true) { 
		cin >> n >> m >> q >> src;
		if (!n && !m && !q && !src) break;
		vector<edge> Edge;
		for (int i = 0; i < m; i++) {
			int u, v, w; cin >> u >> v >> w;
			Edge.push_back({u,v,w});
		}
		vector<int> dst(n,INF);
		BellmanFord(Edge,src,dst);
		while (q--) {
			int x; cin >> x;
			if (dst[x] == -INF) cout << "-Infinity" << endl;
			else if (dst[x] == INF) cout << "Impossible" << endl;
			else cout << dst[x] << endl;
		}
		cout << endl;
	}
}
