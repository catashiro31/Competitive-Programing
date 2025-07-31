#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF INT_MAX
using ll = long long;
using namespace std;
int n, m;
void Dijkstra(vector<pair<int,int>> adjList[], int src, int fn) {
	vector<int> dist(n,INF);
	vector<int> tracer(n,-1);
	dist[src] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,src});
	while (!pq.empty()) {
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (d > dist[u]) continue;
		for (auto x : adjList[u]) {
			int v = x.first;
			int w = x.second;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u]+w;
				pq.push({dist[v],v});
				tracer[v] = u;
			}
		}
	}
	int x = fn;
	vector<int> paths;
	while (tracer[x] != -1) {
		paths.push_back(x);
		x = tracer[x];
	}
	cout << dist[fn] << endl;
	cout << src+1 << " --> ";
	for (int i = paths.size()-1; i >= 0; i--) {
		cout << paths[i]+1 << (i == 0 ? "\n" : " --> ");
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	vector<pair<int,int>> adjList[n];
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adjList[u-1].push_back({v-1,w});
	}
	int src, fn; cin >> src >> fn;
	Dijkstra(adjList,src-1,fn-1);
}
