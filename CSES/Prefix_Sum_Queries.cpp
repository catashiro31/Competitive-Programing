#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005
vector<int> a(MAXN), prefix(MAXN,0);
vector<int> segtree(4*MAXN), lazy(4*MAXN,0);

void build (int id, int l, int r) {
	if (l == r) {
		segtree[id] = prefix[l];
		return;
	}
	int m = (l+r)>>1;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	segtree[id] = max(segtree[id*2], segtree[id*2+1]);
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
	if (r < u || v < l) return;
	if (u <= l && r <= v) {
		segtree[id] += val;
		lazy[id] += val;
		return;
	}
	int m = (l+r)>>1;
	push(id);
	update(id*2,l,m,u,v,val);
	update(id*2+1,m+1,r,u,v,val);
	segtree[id] = max(segtree[id*2], segtree[id*2+1]);
}

int query(int id, int l, int r, int u, int v) {
	if (r < u || v < l) return LLONG_MIN;
	if (u <= l && r <= v) return segtree[id];
	int m = (l+r)>>1;
	push(id);
	int get1 = query(id*2,l,m,u,v), get2 = query(id*2+1,m+1,r,u,v);
	return max(get1,get2);
}

void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i];
	build(1,1,n);
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int k, x; cin >> k >> x;
			update(1,1,n,k,n,x-a[k]);
			a[k] = x;
		} else {
			int u, v; cin >> u >> v;
			int kq  = query(1,1,n,u,v);
			if (u > 1) kq -= query(1,1,n,u-1,u-1);
			cout << max(kq,0LL) << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
