#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005
vector<vector<int>> adj(MAXN);
vector<vector<int>> lca(19, vector<int>(MAXN));
vector<int> degree(MAXN), cnt(MAXN,0), val(MAXN);
void dfs(int u, int par) {
	lca[0][u] = par;
	for (int k = 1; k < 19; k++) lca[k][u] = lca[k-1][lca[k-1][u]];
	for (int v : adj[u]) {
		if (v == par) continue;
		degree[v] = degree[u] + 1;
		dfs(v,u);
	}
}

int get_lca(int u, int v) {
	if (degree[u] > degree[v]) swap(u,v);
	int dif = degree[v] - degree[u];
	for (int k = 0; k < 19; k++) {
		if (dif & (1<<k)) v = lca[k][v];
	}
	if (u == v) return u;
	for (int k = 18; k >= 0; k--) {
		if (lca[k][u] == lca[k][v]) continue;
		u = lca[k][u], v = lca[k][v];
	}
	return lca[0][u];
}

void find_kq(int u, int par) {
	for (int v : adj[u]) {
		if (v == par) continue;
		find_kq(v,u);
		val[u] += val[v];
	}
	val[u] += cnt[u];
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		adj[u].psb(v);
		adj[v].psb(u);
	}	
	degree[1] = 1;
	dfs(1,0);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cnt[a]++, cnt[b]++;
		int c = get_lca(a,b);
		cnt[c]--;
		int pc = lca[0][c];
    	if (pc != 0) cnt[pc]--;
	}
	find_kq(1,0);
	for (int i = 1; i <= n; i++) cout << val[i] << " ";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
