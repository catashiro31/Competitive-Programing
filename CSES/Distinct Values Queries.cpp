#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005
vector<int> a(MAXN);
vector<set<int>> segtree(4*MAXN);
void build(int id, int l, int r) {
	if (l == r) {
		segtree[id].insert(a[l]);
		return;
	}
	int m = (l+r)>>1;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	for (int x : segtree[id*2]) segtree[id].insert(x);
	for (int x : segtree[id*2+1]) segtree[id].insert(x);
}

set<int> query(int id, int l, int r, int u, int v) {
	if (r < u || v < l) return {};
	if (u <= l && r <= v) return segtree[id];
	int m = (l+r)>>1;
	set<int> res;
	set<int> get1 = query(id*2,l,m,u,v), get2 = query(id*2+1,m+1,r,u,v);
	for (int x : get1) res.insert(x);
	for (int x : get2) res.insert(x);
	return res;
}

void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	while (q--) {
		int u, v; cin >> u >> v;
		set<int> kq = query(1,1,n,u,v);
		cout << sz(kq) << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
