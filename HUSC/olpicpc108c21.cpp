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
struct info {
	int csum, cmax, cmin;
	int slmin = 0, slmax = 0;
};

int a[MAXN], lazy[4*MAXN];
info segtree[4*MAXN];

inline void update_base(int id) {
	segtree[id].csum = segtree[id*2].csum + segtree[id*2+1].csum;
	segtree[id].cmax = max(segtree[id*2].cmax, segtree[id*2+1].cmax);
	segtree[id].cmin = min(segtree[id*2].cmin, segtree[id*2+1].cmin);
	segtree[id].slmin = 0, segtree[id].slmax = 0;
	if (segtree[id*2].cmin == segtree[id].cmin) segtree[id].slmin += segtree[id*2].slmin;
	if (segtree[id*2+1].cmin == segtree[id].cmin) segtree[id].slmin += segtree[id*2+1].slmin;
	if (segtree[id*2].cmax == segtree[id].cmax) segtree[id].slmax += segtree[id*2].slmax;
	if (segtree[id*2+1].cmax == segtree[id].cmax) segtree[id].slmax += segtree[id*2+1].slmax;
	return; 
}

void build(int id, int l, int r) {
	if (l == r) {
		segtree[id].csum = a[l];
		segtree[id].cmax = a[l];
		segtree[id].cmin = a[l];
		segtree[id].slmin = 1;
		segtree[id].slmax = 1;
		return;
	}
	int m = (l+r)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	update_base(id);
}

inline void push(int id, int l, int r) {
	if (!lazy[id]) return;
	int m = (l+r)/2;
	segtree[id*2].csum += lazy[id]*(m-l+1);
	segtree[id*2+1].csum += lazy[id]*(r-m);
	segtree[id*2].cmin += lazy[id];
	segtree[id*2].cmax += lazy[id];
	segtree[id*2+1].cmax += lazy[id];
	segtree[id*2+1].cmin += lazy[id];
	lazy[id*2] += lazy[id];
	lazy[id*2+1] += lazy[id];
	lazy[id] = 0;
	return;
}

void update1(int id, int l, int r, int u, int v, int x) {
	if (r < u || v < l) return;
	if (u <= l && r <= v) {
		segtree[id].csum += x*(r-l+1);
		segtree[id].cmax += x;
		segtree[id].cmin += x; 
		lazy[id] += x;
		return;
	}
	push(id,l,r);
	int m = (l+r)/2;
	update1(id*2,l,m,u,v,x);
	update1(id*2+1,m+1,r,u,v,x);
	update_base(id);
}

info query(int id, int l, int r, int u, int v) {
	info epty;
	epty.csum = 0, epty.cmax = LLONG_MIN, epty.cmin = LLONG_MAX;
	epty.slmax = 0, epty.slmin = 0;
	if (r < u || v < l) return epty;
	if (u <= l && r <= v) return segtree[id];
	push(id,l,r);
	int m = (l+r)/2;
	info q1 = query(id*2,l,m,u,v), q2 = query(id*2+1,m+1,r,u,v);
	info res;
	res.csum = q1.csum + q2.csum;
	res.cmin = min(q1.cmin,q2.cmin);
	res.cmax = max(q1.cmax,q2.cmax);
	res.slmax = 0, res.slmin = 0;
	if (q1.cmax == res.cmax) res.slmax += q1.slmax;
	if (q2.cmax == res.cmax) res.slmax += q2.slmax;
	if (q1.cmin == res.cmin) res.slmin += q1.slmin;
	if (q2.cmin == res.cmin) res.slmin += q2.slmin;
	return res;
}

void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 5000 && q <= 5000) {
		while (q--) {
			int t; cin >> t;
			if (t <= 3) {
				int l, r, x; cin >> l >> r >> x;
				for (int i = l;	 i <= r; i++) {
					if (t == 1) a[i] += x;
					else if (t == 3) a[i] = max(a[i],x);
					else a[i] = min(a[i],x);
				}
			} else {
				int l, r; cin >> l >> r;
				int csum = 0, cmax = LLONG_MIN, slmax = 0, cmin = LLONG_MAX, slmin = 0;
				for (int i = l; i <= r; i++) {
					csum += a[i];
					if (cmax < a[i]) {
						cmax = a[i], slmax = 1;
					} else if (cmax == a[i]) slmax++;
					if (cmin > a[i]) {
						cmin = a[i], slmin = 1;
					} else if (cmin == a[i]) slmin++;
				}
				if (t == 4) cout << csum << endl;
				else if (t == 5) cout << cmax << endl;
				else if (t == 6) cout << slmax << endl;
				else if (t == 7) cout << cmin << endl;
				else cout << slmin << endl;
			}
		}
		return;
	}
	build(1,1,n);
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int l, r, x; cin >> l >> r >> x;
			update1(1,1,n,l,r,x);
		} else {
			int l, r; cin >> l >> r;
			info res = query(1,1,n,l,r);
			if (t == 4) cout << res.csum << endl;
			else if (t == 5) cout << res.cmax << endl;
			else if (t == 6) cout << res.slmax << endl;
			else if (t == 7) cout << res.cmin << endl;
			else cout << res.slmin << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}