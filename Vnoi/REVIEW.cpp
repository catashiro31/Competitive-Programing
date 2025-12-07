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
vector<int> trai(4*MAXN, LLONG_MAX), phai(4*MAXN, LLONG_MAX);
vector<int> a(MAXN);
int n, q;
void build(int id, int l, int r) {
	if (l == r) {
		trai[id] = l + a[l];
		phai[id] = (n-l+1) + a[l];
		return;
	}
	int m = (l+r)>>1;
	build(id<<1,l,m);
	build(id<<1|1,m+1,r);
	trai[id] = min(trai[id<<1], trai[id<<1|1]);
	phai[id] = min(phai[id<<1], phai[id<<1|1]);
}

void update(int id, int l, int r, int p, int val) {
	if (p < l || r < p) return;
	if (l == r) {
		trai[id] = trai[id] - a[p] + val;
		phai[id] = phai[id] - a[p] + val;
		a[p] = val;
		return;
	}
	int m = (l+r)>>1;
	update(id<<1,l,m,p,val);
	update(id<<1|1,m+1,r,p,val);
	trai[id] = min(trai[id<<1], trai[id<<1|1]);
	phai[id] = min(phai[id<<1], phai[id<<1|1]);
}

int query(int id, int l, int r, int u, int v, const vector<int> &segtree) {
	if (r < u || v < l) return LLONG_MAX;
	if (u <= l && r <= v) return segtree[id];
	int m = (l+r)>>1;
	int get1 = query(id<<1,l,m,u,v,segtree), get2 = query(id<<1|1,m+1,r,u,v,segtree);
	return min(get1,get2);
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int k, x; cin >> k >> x;
			update(1,1,n,k,x);
		} else {
			int k; cin >> k;
			int get1 = query(1,1,n,k,n,trai) - k;
			int get2 = query(1,1,n,1,k,phai) - (n-k+1);
			cout << min(get1,get2) << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
