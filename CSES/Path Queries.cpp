#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005
vector<vector<int>> adj(MAXN);
vector<int> path(MAXN), segtree(4*MAXN), lazy(4*MAXN), a(MAXN);
vector<int> st(MAXN), en(MAXN), flat(MAXN);
int timer = 1;
void dfs(int u, int par) {
	st[u] = timer++;
	flat[st[u]] = path[u];
	for (int v : adj[u]) {
		if (v == par) continue;
		path[v] = path[u] + a[v];
		dfs(v,u);
	}
	en[u] = timer-1;
}

void build(int id, int l, int r) {
	if (l == r) {
		segtree[id] = flat[l];
		return;
	}
	int m = (l+r)>>1;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
}

void push(int id) {
	if (!lazy[id]) return;
	lazy[id*2] += lazy[id];
	lazy[id*2+1] += lazy[id];
	segtree[id*2] += lazy[id];
	segtree[id*2+1] += lazy[id];
	lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
	if (v < l || r < u) return;
	if (u <= l && r <= v) {
		segtree[id] += val;
		lazy[id] += val;
		return;
	}
	push(id);
	int m = (l+r)>>1;
	update(id*2,l,m,u,v,val);
	update(id*2+1,m+1,r,u,v,val);
}

int getv(int id, int l, int r, int p) {
	if (p < l || r < p) return -1;
	if (l == r) return segtree[id];
	push(id);
	int m = (l+r)>>1;
	if (p <= m) return getv(id*2,l,m,p);
	return getv(id*2+1,m+1,r,p);
}

void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		adj[u].psb(v);
		adj[v].psb(u);
	}
	path[1] = a[1];
	dfs(1,0);
	build(1,1,n);
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int u, x; cin >> u >> x;
			update(1,1,n,st[u],en[u],x-a[u]);
			a[u] = x;
		} else {
			int u; cin >> u;
			cout << getv(1,1,n,st[u]) << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
