#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int par[MAXN], sz_vertile[MAXN], sz_edge[MAXN];

int _find(int u) {
	if (par[u] == u) return u;
	return par[u] = _find(par[u]);
}

void _union(int u, int v) {
	int pu = _find(u), pv = _find(v);
	if (pu == pv) {
		sz_edge[pu]++;
		return;
	}
	if (pu < pv) swap(pu,pv);
	par[pu] = pv;
	sz_vertile[pv] += sz_vertile[pu]; 
	sz_edge[pv] += sz_edge[pu] +1;
}


void solve() {
	int n; cin >> n;
	for (int i = 0; i < MAXN; i++) par[i] = i, sz_vertile[i] = 1;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		_union(a,b);
	}
	int kq = 0;
	for (int i = 1; i <= n; i++) {
		if (par[i] != i) continue;
		kq += min(sz_vertile[i],sz_edge[i]);
	}
	cout << kq;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	while(t--) solve();
}