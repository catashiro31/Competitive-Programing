#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005
vector<vector<int>> lca(18,vector<int>(MAXN,0)), cmin(18,vector<int>(MAXN,INT_MAX));
vector<vector<pair<int,int>>> adj(MAXN);
vector<int> par(MAXN,0), degree(MAXN);

int find_set(int u) {
	if (par[u] == u) return u;
	return par[u] = find_set(par[u]);
}

bool union_set(int u, int v) {
	int pu = find_set(u), pv = find_set(v);
	if (pu == pv) return false;
	if (pu < pv) swap(pu,pv);
	par[pv] = pu;
	return true;
}

void dfs(int u, int par, int w) {
	lca[0][u] = par;
	cmin[0][u] = w;
	for (int k = 1; k < 18; k++) {
		lca[k][u] = lca[k-1][lca[k-1][u]]; 
		cmin[k][u] = min(cmin[k-1][u], cmin[k-1][lca[k-1][u]]);
	}
	for (auto [v,x] : adj[u]) {
		if (v == par) continue;
		degree[v] = degree[u] + 1;
		dfs(v,u,x);
	}
}

int getv(int u, int v) {
	if (degree[u] < degree[v]) swap(u,v);
	int dif = degree[u] - degree[v];
	int res = INT_MAX;
	for (int k = 0; k < 18; k++) {
		if (dif & (1<<k)) res = min(res, cmin[k][u]), u = lca[k][u];
	}
	if (u == v) return res;
	for (int k = 17; k >= 0; k--) {
		if (lca[k][u] != lca[k][v]) {
			res = min(res, cmin[k][u]);
			res = min(res, cmin[k][v]);
			u = lca[k][u];
			v = lca[k][v];
		}
	}
	res = min(res,cmin[0][u]);
	res = min(res,cmin[0][v]);
	return res;
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < MAXN; i++) par[i] = i;
	priority_queue<pair<int,pair<int,int>>> pq;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		pq.push({w,{u,v}});
	}
	vector<pair<pair<int,int>,int>> arr;
	while (!pq.empty()) {
		auto [w,uv] = pq.top(); pq.pop();
		auto [u,v] = uv;
		if (!union_set(u,v)) {
			arr.psb({{u,v},w});	
		} else {
			adj[u].psb({v,w});
			adj[v].psb({u,w});
		}
	}
	degree[1] = 1;
	dfs(1,0,INT_MAX);
	int kq = 0;	
	for (auto [uv, w] : arr) {
		auto [u,v] = uv;
//		cout << w << " " << u << " " << v << " " << getv(u,v) << endl;
		kq += getv(u,v) - w;
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
