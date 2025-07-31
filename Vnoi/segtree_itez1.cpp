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
int a[MAXN], greatest[MAXN*4];
void build(int id, int l, int r) {
	if (l == r) {
		greatest[id] = a[l];
		return;
	}
	int m = (l+r)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	greatest[id] = max(greatest[id*2],greatest[id*2+1]);
}
void update(int id, int l, int r, int p, int val) {
	if (p < l || p > r) return;
	if (l == r) {
		a[p] = val;
		greatest[id] = val;
		return;
	}
	int m = (l+r)/2;
	update(id*2,l,m,p,val);
	update(id*2+1,m+1,r,p,val);
	greatest[id] = max(greatest[id*2],greatest[id*2+1]);
}
int get(int id, int l, int r, int u, int v) {
	if (v < l || u > r) return INT_MIN;
	if (u <= l && r <= v) return greatest[id];
	int m = (l+r)/2;
	int tmp1 = get(id*2,l,m,u,v);
	int tmp2 = get(id*2+1,m+1,r,u,v);
	return max(tmp1,tmp2);
}
void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x, val; cin >> x >> val;
			update(1,1,n,x,val);
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
