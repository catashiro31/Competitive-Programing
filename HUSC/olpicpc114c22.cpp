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

void dfs(int u,const vector<vector<int>> &adj, vector<bool> &used) {
	for (int v : adj[u]) {
		if (used[v]) continue;
		used[v] = true;
		dfs(v,adj,used);
	}
}

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<pair<int,int>> edge(m);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		edge[i] = {u,v};
		adj[u].psb(v);
		adj[v].psb(u);
	}
	int kq = 0;
	for (int i = 0; i < m; i++) {
		vector<bool> used(n,false);
		used[edge[i].fi] = true, used[edge[i].se] = true;
		if (edge[i].fi && edge[i].se) dfs(0,adj,used);
		else if (edge[i].fi != 1 && edge[i].se != 1) dfs(1,adj,used);
		else dfs(2,adj,used);
		bool check = true;;
		for (int i = 0; i < n; i++) check = (check && used[i]);
		if (!check) kq++; 
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
