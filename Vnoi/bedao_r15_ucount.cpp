#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
int n, m, k;
void DFS(int u, vector<int> &par, const vector<vector<int>> &adj, vector<int> &visited, int dst) {
	if (u == dst) {
		int v = u;
		while (par[v] != v) visited[v]++, v = par[v];
		visited[v]++;
		return;
	}
	for (int v : adj[u]) {
		if (v == par[u]) continue;
		par[v] = u;
		DFS(v,par,adj,visited,dst);
	}
}
vector<int> choose;
int kq = 0;
void backtrack(int u, int k, const vector<pair<int,int>> &path, const vector<vector<int>> &adj) {
	if (u == k) {
		vector<int> visited(n,0), par(n,0);
		for (int i = 0; i < choose.size(); i++) {
			int src = path[choose[i]].first, en = path[choose[i]].second;
			par[src] = src; 
			DFS(src, par, adj, visited, en);
		}
		for (int i = 0; i < n; i++) {
			if (visited[i] == k) {
				kq++;
				return;
			}
		}
		return;
	}
	for (int i = 0; i < path.size(); i++) {
		if (choose.empty()) {
			choose.psb(i);
			backtrack(u+1,k,path,adj);
			choose.pop_back();
		} else {
			if (choose[choose.size()-1] >= i) continue;
			choose.psb(i);
			backtrack(u+1,k,path,adj);
			choose.pop_back();
		}
	}	
}

void solve() {
	cin >> n >> m >> k;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].psb(v);
		adj[v].psb(u);
	}
	vector<pair<int,int>> path(m);
	for (int i = 0; i < m; i++) {
		cin >> path[i].first >> path[i].second;
		path[i].first--, path[i].second--;
	}
	backtrack(0,k,path,adj);
	cout << kq;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
