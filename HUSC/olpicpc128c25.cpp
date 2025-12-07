#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].psb(v);
		adj[v].psb(u);
	}
	vector<int> d(n);
	for (int i = 0; i < n; i++) cin >> d[i];
	int cnt = 0;
	for (int i = 1; i < n; i++) if (d[i] == -1) cnt++;
	if (cnt == n-1) {
		if (d[0] == -1) {
			cout << n << endl;
			for (int i = 0; i < n; i++) cout << i+1 << " ";
			return;
		} 
		vector<bool> vis(n,false);
		vector<int> dist(n);
		queue<int> q;
		q.push(0);
		dist[0] = 0;
		vis[0] = true;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : adj[u]) {
				if (vis[v]) continue;
				vis[v] = true;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
		vector<int> kq;
		for (int j = 0; j < n; j++) if (dist[j] == d[0]) kq.psb(j+1);
		cout << kq.size() << endl;
		for (int x : kq) cout << x << " ";
		return;
	}
	vector<int> kq;
	for (int i = 0; i < n; i++) {
		vector<bool> vis(n,false);
		vector<int> dist(n);
		dist[i] = 0;
		vis[i] = true;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : adj[u]) {
				if (vis[v]) continue;
				vis[v] = true;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
		bool c = true;
		for (int j = 0; j < n; j++) {
			if (d[j] != -1 && dist[j] != d[j]) c = false;
		}
		if (c) kq.psb(i+1);
	}
	cout << kq.size() << endl;
	for (int x : kq) cout << x << " ";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
