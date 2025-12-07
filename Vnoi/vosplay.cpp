#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005
vector<map<int,int>> game;
vector<int> sl, kq, par;

int find_set(int u) {
	if (par[u] == u) return u;
	return par[u] = find_set(par[u]);
}

void union_set(int u, int v, int k) {
	int pu = find_set(u), pv = find_set(v);
	if (pu == pv) return;
	if (game[pu].size() < game[pv].size()) swap(pu,pv);
	par[pv] = pu;
	for (auto p : game[pv]) {
		game[pu][p.first] += p.second;
		if (game[pu][p.first] == sl[p.first] && kq[p.first] == -1) kq[p.first] = k;
	}
	game[pv].clear();
	return;
}

void solve() {
	int n, m, q; cin >> n >> m >> q;
	game.assign(n+1,map<int,int>());
	sl.assign(m+1,0), kq.assign(m+1,-1);
	par.assign(n+1,0);
	for (int i = 1; i <= n; i++) {
		int g; cin >> g;
		sl[g]++, game[i][g]++, par[i] = i;
	}
	for (int i = 1; i <= q; i++) {
		int u, v; cin >> u >> v;
		union_set(u,v,i);
	}
	for (int i = 1; i <= m; i++) {
		if (sl[i] == 1) cout << 0 << endl;
		else cout << kq[i] << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
