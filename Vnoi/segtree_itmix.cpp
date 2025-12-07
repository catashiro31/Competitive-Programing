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
vector<int> a(MAXN), segtree(4*MAXN,0), lazy1(4*MAXN,1), lazy2(4*MAXN,0);

void build(int id,int l, int r) {
	if (l == r) {
		segtree[id] = a[l];
		return;
	}
	int m = (l+r)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	segtree[id] = (segtree[id*2] + segtree[id*2+1]) % MOD;
}

void push(int id, int l, int r) {
	if (lazy1[id] != 1) {
		segtree[id*2] = (segtree[id*2] * lazy1[id]) % MOD;
		segtree[id*2+1] = (segtree[id*2+1] * lazy1[id]) % MOD;
		lazy1[id*2] = (lazy1[id*2] * lazy1[id]) % MOD;
		lazy1[id*2+1] = (lazy1[id*2+1] * lazy1[id]) % MOD;
		lazy2[id*2] = (lazy2[id*2] * lazy1[id]) % MOD;
		lazy2[id*2+1] = (lazy2[id*2+1] * lazy1[id]) % MOD;
		lazy1[id] = 1;
	}
	int m = (l+r)/2;
	if (lazy2[id]) {
		segtree[id*2] = (segtree[id*2] + lazy2[id]*(m-l+1)) % MOD;
		segtree[id*2+1] = (segtree[id*2+1] + lazy2[id]*(r-m)) % MOD;
		lazy2[id*2] = (lazy2[id*2] + lazy2[id]) % MOD;
		lazy2[id*2+1] = (lazy2[id*2+1] + lazy2[id]) % MOD;
		lazy2[id] = 0;
	}
}

void update2(int id, int l, int r, int u, int v, int val) {
	if (r < u || v < l) return;
	if (u <= l && r <= v) {
		segtree[id] = (segtree[id] * val) % MOD;
		lazy1[id] = (lazy1[id] * val) % MOD;
		lazy2[id] = (lazy2[id] * val) % MOD;
		return;
	}
	int m = (l+r)/2;
	push(id,l,r);
	update2(id*2,l,m,u,v,val);
	update2(id*2+1,m+1,r,u,v,val);
	segtree[id] = (segtree[id*2] + segtree[id*2+1]) % MOD;
}

void update1(int id, int l, int r, int u, int v, int val) {
	if (r < u || v < l) return;
	if (u <= l && r <= v) {
		segtree[id] = (segtree[id] + val*(r-l+1)) % MOD;
		lazy2[id] = (lazy2[id] + val) % MOD;
		return;
	}
	int m = (l+r)/2;
	push(id,l,r);
	update1(id*2,l,m,u,v,val);
	update1(id*2+1,m+1,r,u,v,val);
	segtree[id] = (segtree[id*2] + segtree[id*2+1]) % MOD;
}

void update3(int id, int l, int r, int u, int v, int val) {
	if (r < u || v < l) return;
	if (u <= l && r <= v) {
		segtree[id] = (val*(r-l+1)) % MOD;
		lazy1[id] = 0;
		lazy2[id] = val;
		return;
	}
	int m = (l+r)/2;
	push(id,l,r);
	update3(id*2,l,m,u,v,val);
	update3(id*2+1,m+1,r,u,v,val);
	segtree[id] = (segtree[id*2] + segtree[id*2+1]) % MOD;
}

int query(int id, int l, int r, int u, int v) {
	if (r < u || v < l) return 0;
	if (u <= l && r <= v) return segtree[id];
	int m = (l+r)/2;
	push(id,l,r);
	int q1 = query(id*2,l,m,u,v), q2 = query(id*2+1,m+1,r,u,v);
	return (q1 + q2) % MOD;
}

void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int u, v, x; cin >> u >> v >> x;
			update1(1,1,n,u,v,x);
		} else if (t == 2) {
			int u, v, x; cin >> u >> v >> x;
			update2(1,1,n,u,v,x);
		} else if (t == 3) {
			int u, v, x; cin >> u >> v >> x;
			update3(1,1,n,u,v,x);
		} else {
			int u, v; cin >> u >> v;
			cout << query(1,1,n,u,v) << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
