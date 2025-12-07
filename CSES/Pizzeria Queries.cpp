#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void build(vector<int> &segtree, int id, int l, int r, vector<int> &arr) {
	if (l == r) {
		segtree[id] = arr[l];
		return;
	}
	int m = (l+r)>>1;
	build(segtree,id*2,l,m,arr);
	build(segtree,id*2+1,m+1,r,arr);
	segtree[id] = min(segtree[id*2], segtree[id*2+1]);
}

void update(vector<int> &segtree, int id, int l, int r, int pos, int val) {
	if (pos < l || r < pos) return;
	if (l == r) {
		segtree[id] += val;
		return;
	}
	int m = (l+r)>>1;
	update(segtree,id*2,l,m,pos,val);
	update(segtree,id*2+1,m+1,r,pos,val);
	segtree[id] = min(segtree[id*2], segtree[id*2+1]);
} 

int query(vector<int> &segtree, int id, int l, int r, int u, int v) {
	if (v < l || r < u) return LLONG_MAX;
	if (u <= l && r <= v) return segtree[id];
	int m = (l+r)>>1;
	int get1 = query(segtree,id*2,l,m,u,v), get2 = query(segtree,id*2+1,m+1,r,u,v);
	return min(get1,get2);
}

void solve() {
	int n, q; cin >> n >> q;
	vector<int> p(n+1);
	for (int i = 1;  i <= n; i++) cin >> p[i];
	vector<int> l(n+1), r(n+1), segtree1(4*n), segtree2(4*n);
	for (int i = 1; i <= n; i++) l[i] = i + p[i];
	for (int i = 1; i <= n; i++) r[n-i+1] = i + p[n-i+1];
	build(segtree1,1,1,n,l);
	build(segtree2,1,1,n,r);
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int k, x; cin >> k >> x;
			update(segtree1,1,1,n,k,x-p[k]);
			update(segtree2,1,1,n,k,x-p[k]);
			p[k] = x;
		} else {
			int k; cin >> k;
			int get1 = query(segtree1,1,1,n,k,n), get2 = query(segtree2,1,1,n,1,k);
			cout << min(get1-k,get2-(n-k+1)) << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
