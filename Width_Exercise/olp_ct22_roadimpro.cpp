#include <bits/stdc++.h>
#define endl '\n'
#define INF LLONG_MAX
using namespace std;
using ll = long long;
struct Edge {
    int u, v, w;
};
void dijkstra(const vector<vector<pair<int, int>>> &adj, vector<ll> &dist, int src) {
    dist[src] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> adj(n);
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--; 
        adj[u].emplace_back(v, w);
        edges.push_back({u, v, w});
    }
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++) {
        dijkstra(adj, dist[i], i); 
    }
     sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w > b.w;
    });
    while (q--) {
        int s, t;
        cin >> s >> t;
        s--;  
        ll res = dist[0][s];
        for (auto [u,v,w] : edges) {
        	if (w <= t) break;
            if (dist[0][u] != INF && dist[v][s] != INF) {
                res = min(res, dist[0][u] + t + dist[v][s]);
            }
        }
		cout << res << endl;
    }
    return 0;
}
