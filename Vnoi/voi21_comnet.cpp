#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

int combinations(int n, int k) {
	if (k > n || k < 0) return 0;
	int res = 1;
	for (int i = n; i > n-k; i--) res *= i;
	return res; 
}

void solve() {
	int n, k, a, b; cin >> n >> k >> a >> b;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].psb(v);
		adj[v].psb(u);
	}
	int kq = 0;
	for (int i = 0; i < n; i++) {
		queue<int> q;
		q.push(i);
		vector<int> degree(n,-1);
		degree[i] = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			if (degree[u] > b) continue;
			if (degree[u] >= a && u >= i) kq += combinations(degree[u]-1,k-2);
			for (int v : adj[u]) {
				if (degree[v] != -1) continue;
				degree[v] = degree[u] + 1;
				q.push(v);
			}
		}
		cout << i << " " << kq << endl;
	}
	cout << kq;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
