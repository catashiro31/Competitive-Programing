#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define int long long
#define sz(x) x.size()
#define MOD 1000000007
#define MAXN 200005

vector<map<int,int>> color;
vector<int> par;

int find_set(int u) {
	if (par[u] == u) return u;
	return par[u] = find_set(par[u]);
}

void union_set(int u, int v) {
	int pu = find_set(u), pv = find_set(v);
	if (pv == pu) return;
	if (color[pv].size() > color[pu].size()) swap(pv,pu);
	par[pv] = pu; 
	for (auto p : color[pv]) color[pu][p.first] += p.second;
	return;
}

inline int query(int u, int c) {
	int pu = find_set(u);
	return color[pu][c];
}

void solve() {
	int n, q; cin >>  n >> q;
	color.assign(n+1,map<int,int>());
	par.assign(n+1,0);
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		int c; cin >> c;
		color[i][c] = 1;
	}
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int u, v; cin >> u >> v;
			union_set(u,v);
		} else {
			int u, c; cin >> u >> c;
			cout << query(u,c) << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
