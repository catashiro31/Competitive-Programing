#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF INT_MAX
using ll = long long;
using namespace std;
int n, m; 
int dijkstra(vector<vector<pair<int,int>>> adjList, int src) {
	vector<int> cost(n,INF);
	cost[src] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,src});
	while (!pq.empty()) {
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if (d > cost[u]) continue;
		for (auto x : adjList[u]) {
			int v = x.first;
			int c = x.second;
			if (cost[u] != INF && cost[u]+c < cost[v]) {
				cost[v] = cost[u]+c;
				pq.push({cost[v],v});
			}
		}
	}
	return cost[n-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	vector<vector<pair<int,int>>> adjList(n);
	vector<int> flows;
	for (int i = 0; i < m; i++) {
		int a, b, c, f; cin >> a >> b >> c >> f;
		flows.push_back(f);
		adjList[a-1].push_back({b-1,c});
		adjList[b-1].push_back({a-1,c});
	}
	int ans = 0;
	for (int i = 0; i < ; i++) {
		int cmin = dijkstra(adjList,)
		double tmp = 1.0*x/cmin;
		ans = max(ans,(int)(tmp*1e6));
	}
	cout << ans;
}
