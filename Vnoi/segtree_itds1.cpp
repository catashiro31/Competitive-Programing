#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 2e5+1;
const int MOD = 1e9+7;
const string NoF = "Name_of_File";
int a[MAXN];
multiset<int> segtree[MAXN*4];
void build(int id, int l, int r) {
	if (l == r) {
		segtree[id].insert(a[l]);
		return;
	}
	int m = (l+r)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	for (int x : segtree[id*2]) segtree[id].insert(x);
	for (int x : segtree[id*2+1]) segtree[id].insert(x);
}
void update(int id, int l, int r, int p, int val1, int val2) {
	if (p < l || p > r) return;
	if (l == r) {
		auto it = segtree[id].find(val2);
		segtree[id].erase(it);
		segtree[id].insert(val1);
		a[p] = val1;
		return;
	}
	int m = (l+r)/2;
	update(id*2,l,m,p,val1,val2);
	update(id*2+1,m+1,r,p,val1,val2);
	auto it = segtree[id].find(val2);
	segtree[id].erase(it);
	segtree[id].insert(val1);
}
int get(int id, int l, int r, int u, int v, int k) {
	if (v < l || u > r) return -1;
	if (u <= l && r <= v) {
		auto it = segtree[id].lower_bound(k);
		if (it != segtree[id].end()) return *it;
		return -1;
	}
	int m = (l+r)/2;
	int tmp1 = get(id*2,l,m,u,v,k);
	int tmp2 = get(id*2+1,m+1,r,u,v,k);
	if (min(tmp1,tmp2) == -1 && max(tmp1,tmp2) == -1) return -1;
	else if (min(tmp1,tmp2) == -1) return max(tmp1,tmp2);
	return min(tmp1,tmp2);
}
void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	while (m--) {
		int t; cin >> t;
		if (t == 1) {
			int i, v; cin >> i >> v;
			update(1,1,n,i,v,a[i]);
		} else {
			int l, r, k; cin >> l >> r >> k;
			cout << get(1,1,n,l,r,k) << endl;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
