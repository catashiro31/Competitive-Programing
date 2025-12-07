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
int par[MAXN], sl[MAXN];

int _find(int u) {
	if (par[u] == u) return u;
	return par[u] = _find(par[u]);
}

void _union(int u, int v) {
	int pu = _find(u), pv = _find(v);
	if (pu == pv) return;
	if (pu > pv) swap(pu,pv);
	par[pv] = pu;
	sl[pu] += sl[pv];
	return;
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i <= n; i++) par[i] = i, sl[i] = 1;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		_union(u,v);
	}
	int kq = sl[1], cmax = 0;
	for (int i = 2; i <= n; i++) {
		if (_find(i) != 1) cmax = max(cmax, sl[i]);
	}
	kq = kq + cmax;
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
