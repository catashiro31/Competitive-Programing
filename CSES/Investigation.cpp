#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define MOD 1000000007
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<pair<int,int>>> adjList(n+1);
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adjList[u].psb({v,c});
	}
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
	vector<ll> dist(n+1,LLONG_MAX), num(n+1), cmin(n+1,LLONG_MAX), cmax(n+1,LLONG_MIN);
	dist[1] = 0, num[1] = 1, cmin[1] = 0, cmax[1] = 0;
	vector<bool> visited(n+1,false);
	pq.push({0,1});
	while(!pq.empty()) {
		auto [d,u] = pq.top(); pq.pop();
		if (visited[u]) continue;
		visited[u] = true;
		for (auto [v,c] : adjList[u]) {
			if (dist[u] + c == dist[v]) {
				num[v] = (num[v] + num[u]) % MOD;
				cmin[v] = min(cmin[v],cmin[u]+1);
				cmax[v] = max(cmax[v],cmax[u]+1);
			} else if (dist[u] + c < dist[v]) {
				dist[v] = dist[u]+c;
				num[v] = num[u];
				cmin[v] = cmin[u]+1;
				cmax[v] = cmax[u]+1;
				pq.push({dist[v],v});
			}
		}
	}
	cout << dist[n] << " " << num[n] << " " << cmin[n] << " " << cmax[n] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
