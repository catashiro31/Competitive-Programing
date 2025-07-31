#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF INT_MAX
using ll = long long;
using namespace std;
void dijkstra(vector<vector<pair<int,int>>> adjList, vector<int> &dst, vector<int> &par, int src) {
	dst[src] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,src});
	while (!pq.empty()) {
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if (d > dst[u]) continue;
		for (auto x : adjList[u]) {
			int v = x.first;
			int c = x.second;
			if (dst[u]+c < dst[v]) {
				dst[v] = dst[u] + c;
				pq.push({dst[v],v});
				par[v] = u;
			}
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, k; cin >> n >> m >> k;
	vector<vector<pair<int,int>>> adjList(n);
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adjList[u-1].push_back({v-1,c});
		adjList[v-1].push_back({u-1,c});
	}
	vector<vector<int>> kc(n,vector<int> (n,INF));
	vector<vector<int>> vis(n,vector<int> (n,-1));
	for (int i = 0; i < n; i++) {
		dijkstra(adjList,kc[i],vis[i],i);
	}
	while(k--) {
		int q, u, v; cin >> q >> u >> v;
		u--; v--;
		if (!q) {
			cout << kc[u][v];
		} else {
			vector<int> kq;
			while (vis[u][v] != -1) {
				kq.push_back(v);
				v = vis[u][v];
			}
			kq.push_back(u);
			reverse(kq.begin(),kq.end());
			cout << kq.size() << " ";
			for (int x : kq) cout << x+1 << " ";
		}
		cout << endl;
	}
}