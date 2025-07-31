#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF LLONG_MAX
using ll = long long;
using namespace std;
void dijkstra(vector<vector<pair<int,int>>> adjList, int n, int s, vector<ll> &dist) {
    dist[s] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adjList[u]) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
void solve() {
    int n, m, k, s, t; 
    cin >> n >> m >> k >> s >> t;
    --s, --t;
    vector<vector<pair<int, int>>> adjList(n);
    vector<vector<pair<int, int>>> TadjList(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; 
        cin >> u >> v >> w;
        --u, --v;
        adjList[u].push_back({v, w});
        TadjList[v].push_back({u, w});
    }
    vector<ll> dists(n, INF), distt(n, INF);
    dijkstra(adjList, n, s, dists); 
    dijkstra(TadjList, n, t, distt);  
    ll kq = INF;
    if (dists[t] != INF) 
        kq = dists[t]; 
    for (int i = 0; i < k; i++) {
        int u, v, w; 
        cin >> u >> v >> w;
        --u, --v;
        if (dists[u] != INF && distt[v] != INF) 
            kq = min(kq, dists[u] + distt[v] + w);
        if (dists[v] != INF && distt[u] != INF) 
            kq = min(kq, dists[v] + distt[u] + w);
    }

    if (kq == INF) cout << -1 << endl;
    else cout << kq << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}
