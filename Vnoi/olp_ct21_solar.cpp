#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 1000005
int a[MAXN];
vector<pair<int,int>> segtree(4*MAXN,{0,0});

void build(int id, int l, int r) {
	if (l == r) {
		segtree[id].fi = a[l];
		segtree[id].se = l;
		return;
	}
	int m = (l+r)>>1;
	build(id<<1,l,m);
	build(id<<1|1,m+1,r);
	segtree[id].fi = segtree[id<<1|1].fi + segtree[id<<1].fi;
	segtree[id].se = a[segtree[id<<1].se] <= a[segtree[id<<1|1].se] ? segtree[id<<1].se : segtree[id<<1|1].se;
}

void update(int id, int l, int r, int p, int val) {
	if (p < l || r < p) return;
	if (l == r) {
		segtree[id].fi = val;
		segtree[id].se = l;
		a[l] = val;
		return;
	}
	int m = (l+r)>>1;
	update(id<<1,l,m,p,val);
	update(id<<1|1,m+1,r,p,val);
	segtree[id].fi = segtree[id<<1].fi + segtree[id<<1|1].fi;
	segtree[id].se = a[segtree[id<<1].se] <= a[segtree[id<<1|1].se] ? segtree[id<<1].se : segtree[id<<1|1].se;
}

pair<int,int> query(int id, int l, int r, int u, int v) {
	if (r < u || v < l) return {0,0};
	if (u <= l && r <= v) return segtree[id];
	int m = (l+r)>>1;
	pair<int,int> q1 = query(id<<1,l,m,u,v), q2 = query(id<<1|1,m+1,r,u,v);
	pair<int,int> res = {q1.fi + q2.fi, 0};
	res.se = a[q1.se] <= a[q2.se] ? q1.se : q2.se;
	return res;
}

void solve() {
	int n, q; cin >> n >> q;
	a[0] = INT_MAX;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int rotate = 0;
	build(1,1,n);
	while(q--) {
		int t; cin >> t;
		if (t == 1) {
			int d; cin >> d;
			rotate += d;
		} else if (t == 2) {
			int s, t, p; cin >> s >> t >> p;
			--s, --t, s = ((s - rotate) % n + n) % n, t = ((t - rotate) % n + n) % n;
			s++, t++;
			if (s <= t) {
				auto qr = query(1,1,n,s,t);
				update(1,1,n,qr.se,p);
			} else {
				auto q1 = query(1,1,n,s,n), q2 = query(1,1,n,1,t);
				if (a[q1.se] <= a[q2.se]) update(1,1,n,q1.se,p);
				else update(1,1,n,q2.se,p);
			}
		} else {
			int s, t; cin >> s >> t;
			--s, --t, s = ((s - rotate) % n + n) % n, t = ((t - rotate) % n + n) % n;
			s++, t++;
			if (s <= t) {
				auto qr = query(1,1,n,s,t);
				cout << qr.fi << endl;
			} else {
				auto q1 = query(1,1,n,s,n), q2 = query(1,1,n,1,t);
				cout << q1.fi + q2.fi << endl;
			} 
		}
	}	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
