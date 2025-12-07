#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define MOD 1000000007
#define int long long
#define MAXN 200005
vector<int> segtree(4*MAXN,1), lazy(4*MAXN,1);

void push(int id) {
	segtree[id<<1] = (segtree[id<<1]*lazy[id]) % MOD;
	segtree[id<<1|1] = (segtree[id<<1|1]*lazy[id]) % MOD;
	lazy[id<<1] = (lazy[id<<1]*lazy[id]) % MOD;
	lazy[id<<1|1] = (lazy[id<<1|1]*lazy[id]) % MOD;
	lazy[id] = 1;
}

void update(int id, int l, int r, int u, int v, int val) {
	if (r < u || v < l) return;
	if (u <= l && r <= v) {
		segtree[id] = (segtree[id] * val) % MOD;
		lazy[id] = (lazy[id] * val) % MOD;
		return;
	}
	int m = (l+r)>>1;
	push(id);
	update(id<<1,l,m,u,v,val);
	update(id<<1|1,m+1,r,u,v,val);
}

int query(int id, int l, int r, int p) {
	if (p < l || r < p) return 0;
	if (l == r) return segtree[id];
	int m = (l+r)>>1;
	push(id);
	if (p <= m) return query(id<<1,l,m,p);
	return query(id<<1|1,m+1,r,p);
}

int inv(int base, int exp) {
	int res = 1;
	while(exp) {
		if (exp&1) res = (res * base) % MOD;
		base = (base * base) % MOD;
		exp /= 2;
	}
	return res;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<pair<int,int>> arr(n);
	for (int i = 0 ; i < n; i++) cin >> arr[i].fi >> arr[i].se;
	for (int i = 0; i < n; i++) {
		int l = arr[i].fi, r = arr[i].se;
		if (l <= r) {
			int d = r-l+1;
			int val = ((d-1) * inv(d,MOD-2)) % MOD;
			update(1,1,n,l,r,val);
		} else {
			int d = n-l+1+r;
			int val = ((d-1) * inv(d,MOD-2)) % MOD;
			update(1,1,n,l,n,val);
			update(1,1,n,1,r,val);
		}
	}
	int kq = 0;
	for (int i = 1; i <= n; i++) {
		int x = query(1,1,n,i);
		kq = ((kq - a[i]*x + a[i]*(1-x))%MOD+MOD)%MOD;
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("oneshot.inp","r",stdin);
//	freopen("oneshot.out","w",stdout);
	int t = 1;
	while(t--) solve();
}