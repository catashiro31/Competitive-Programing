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
ll lazy[MAXN*4], segtree[MAXN*4];
void push(int id) {
	if (lazy[id] == 0) return;
	lazy[id*2 ] += lazy[id], lazy[id*2+1] += lazy[id];
	segtree[id*2] += lazy[id], segtree[id*2+1] += lazy[id];
	lazy[id] = 0;
	return; 
}
void update(int id, int l, int r, int u, int v, int val) {
	if (v < l || u > r) return;
	if (u <= l && r <= v) {
		segtree[id] += val;
		lazy[id] += val;
		return;
	}
	int m = (l+r)/2;
	push(id);
	update(id*2,l,m,u,v,val);
	update(id*2+1,m+1,r,u,v,val);
	segtree[id] = max(segtree[id*2],segtree[id*2+1]);
}
ll get(int id, int l, int r, int u, int v) {
	if (v < l || u > r) return INT_MIN;
	if (u <= l && r <= v) return segtree[id];
	int m = (l+r)/2;
	push(id);
	ll tmp1 = get(id*2,l,m,u,v);
	ll tmp2 = get(id*2+1,m+1,r,u,v);
	return max(tmp1,tmp2);
}
void solve() {
	memset(lazy,0,sizeof(lazy));
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int val; cin >> val;
		update(1,1,n,i,i,val);
	}
	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int u, v, val; cin >> u >> v >> val;
			update(1,1,n,u,v,val);
		} else {
			int u, v; cin >> u >> v;
			cout << get(1,1,n,u,v) << endl;
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
