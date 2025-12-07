#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;

struct DSU {
	vector<int> par, sz;
	DSU(int n) {
		par.assign(n,0), sz.assign(n,1);
		for (int i = 0; i < n; i++) par[i] = i;
	}
	
	int _find(int u) {
		if (par[u] == u) return u;
		return par[u] = _find(par[u]);
	}
};

int calculate(const vector<vector<int>> &adj, bool is_max, vector<int> &w) {
	vector<int> p(w.size());
	for (int i = 0; i < w.size(); i++) p[i] = i;
	sort(all(p),[&](auto &a, auto &b) {
		if (is_max) return w[a] < w[b];
		return w[a] > w[b];	
	});
	DSU djs(w.size());
	vector<bool> active(w.size(), false);
    int res = 0;

    for (int i = 0; i < w.size(); i++) {
        int u = p[i];
        active[u] = true;
        
        int cur_sz = 1;

        for (int v : adj[u]) {
            if (active[v]) {
                int root_v = djs._find(v);
                int sz_v = djs.sz[root_v];

                res += w[u] * cur_sz * sz_v;

                djs.par[root_v] = u;
                cur_sz += sz_v;
            }
        }
        djs.sz[u] = cur_sz;
    }
	return res;
}

void solve() {
	int n; cin >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) cin >> w[i];
	vector<vector<int>> adj(n);
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int smax = calculate(adj,true,w);
	int smin = calculate(adj,false,w);
	cout << smax-smin;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	while(t--) solve();
}