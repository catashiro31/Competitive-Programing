#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF LLONG_MAX
using ll = long long;
using namespace std;
void dijkstra(vector<vector<pair<int,ll>>> adjList, int n, int m) {
	int src = (m+1)*n-1;
	vector<ll> dist((m+1)*n,INF);
	dist[src] = 0;
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
	pq.push({0,src});
	while (!pq.empty()) {
		ll d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (d > dist[u]) continue;
		for (auto [v,w] : adjList[u]) {
			if (dist[u]+w < dist[v]) {
				dist[v] = dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
	cout << *min_element(dist.begin(),dist.begin()+n);
}
void solve() {
	int m, n; cin >> m >> n;
	vector<vector<pair<int,ll>>> adjList(n*(m+1));
	for (int i = n; i < (m+1)*n; i+= n) {
		vector<ll> wt(n);
		for (ll &x : wt) cin >> x;
		vector<ll> ws(n-1);
		for (ll &x : ws) cin >> x;
		for (int j = 0; j < n; j++) {
			adjList[i+j].push_back({i+j-n,wt[j]});
			adjList[i+j-n].push_back({i+j,wt[j]});
			if (j > 0) adjList[i + j].push_back({i + j - 1, ws[j-1]}); 
            if (j < n - 1) adjList[i + j].push_back({i + j + 1, ws[j]});
		}
	}
	dijkstra(adjList,n,m);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
