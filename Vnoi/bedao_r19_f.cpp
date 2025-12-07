#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005
vector<vector<int>> adj(MAXN);
vector<int> a(MAXN), st(MAXN), en(MAXN), val(MAXN), flat(MAXN);
vector<int> segtree(4*MAXN,0), lazy(4*MAXN,1);

int timer = 1;
void euler_tour(int u, int par) {
	st[u] = timer++;
	for (int v : adj[u]) {
		if (v == par) continue;
		euler_tour(v,u);
	}
	en[u] = timer-1;
}

void dfs(int u, int par) {
	for (int v : adj[u]) {
		if (v == par) continue;
		val[v] = (val[u] * a[v]) % MOD;
		dfs(v,u);
	}
}

void build(int id, int l, int r) {
	if (l == r) {
		segtree[id] = flat[l];
		return;
	}
	int m = (l+r)>>1;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	segtree[id] = (segtree[id*2] + segtree[id*2+1]) % MOD;
}

void push(int id) {
	if (lazy[id] == 1) return;
	lazy[id*2] = (lazy[id*2] * lazy[id]) %  MOD;
	lazy[id*2+1]  = (lazy[id*2+1] * lazy[id]) % MOD;
	segtree[id*2] = (segtree[id*2] * lazy[id]) % MOD;
	segtree[id*2+1]  = (segtree[id*2+1] * lazy[id]) % MOD;
	lazy[id] = 1;
}

void update(int id, int l, int r, int u, int v, int price) {
	if (r < u || v < l) return;
	if (u <= l && r <= v) {
		segtree[id] = (segtree[id] * price) % MOD;
		lazy[id] = (lazy[id] * price) % MOD;
		return;
	}
	int m = (l+r)>>1;
	push(id);
	update(id*2,l,m,u,v,price);
	update(id*2+1,m+1,r,u,v,price);
	segtree[id] = (segtree[id*2] + segtree[id*2+1]) % MOD;
}

int query(int id, int l, int r, int u, int v) {
	if (r < u || v < l) return 0;
	if (u <= l && r <= v) return segtree[id];
	int m = (l+r)>>1;
	push(id);
	int get1 = query(id*2,l,m,u,v), get2 = query(id*2+1,m+1,r,u,v);
	return (get1 + get2) % MOD;
}

int ndmod(int x) {
	int base = x, exp = MOD-2;
	int res = 1;
	while (exp) {
		if (exp & 1) res = (res * base) % MOD;
		base = (base * base) % MOD;
		exp /= 2; 
	}
	return res;
}

void solve() {
	int n, q; cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		int p; cin >> p;
		adj[p].psb(i);
		adj[i].psb(p);
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	euler_tour(1,0);
	val[1] = a[1];
	dfs(1,0);
	for (int i = 1; i <= n; i++) flat[st[i]] = val[i];
	build(1,1,n);
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int u, x; cin >> u >> x;
			int l = st[u], r = en[u], up = (x * ndmod(a[u])) % MOD;
			a[u] = x;
			update(1,1,n,l,r,up);
		} else {
			int u; cin >> u;
			int l = st[u], r = en[u];
			int q1 = query(1,1,n,l,r), q2 = query(1,1,n,st[u],st[u]);
			int kq = ((q1 * ndmod(q2)) % MOD * a[u]) % MOD;
			cout << kq << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
