#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
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
ll a[MAXN], segtree[MAXN*4];
vector<ll> lazy1(MAXN*4,0), lazy2(MAXN*4,1), lazy3(MAXN*4,0);
void push(int id, ll l, ll r) {
	if (l == r) return;
	ll m = (l+r)/2;
	if (lazy3[id] != 0) {
		lazy3[id*2] = lazy3[id], lazy3[id*2+1] = lazy3[id];
		segtree[id*2] = ((m-l+1)*lazy3[id])%MOD;
		segtree[id*2+1] = ((r-m)*lazy3[id])%MOD;
		lazy3[id] = 0, lazy2[id] = 1, lazy1[id] = 0;
	}
	if (lazy2[id] != 1) {
		lazy2[id*2] = (lazy2[id*2]*lazy2[id])%MOD;
		lazy2[id*2+1] = (lazy2[id*2+1]*lazy2[id])%MOD;
		lazy1[id*2] = (lazy1[id*2]*lazy2[id])%MOD;
		lazy1[id*2+1] = (lazy1[id*2+1]*lazy2[id])%MOD;
		segtree[id*2] = (segtree[id*2]*lazy2[id])%MOD;
		segtree[id*2+1] = (segtree[id*2+1]*lazy2[id])%MOD;
		lazy2[id] = 1; 
	}
	if (lazy1[id] != 0) {
		lazy1[id*2] = (lazy1[id*2]+lazy1[id])%MOD;
		lazy1[id*2+1] = (lazy1[id*2+1]+lazy1[id])%MOD;
		segtree[id*2] = (segtree[id*2]+(m-l+1)*lazy1[id])%MOD;
		segtree[id*2+1] = (segtree[id*2+1]+(r-m)*lazy1[id])%MOD;
		lazy1[id] = 0;
	}
}
void build(int id, ll l, ll r) {
	if (l == r) {
		segtree[id] = a[l];
		return;
	}
	ll m = (l+r)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	segtree[id] = (segtree[id*2]+segtree[id*2+1])%MOD;
}
void update1(int id, ll l, ll r, ll u, ll v, ll x) {
	if (r < u || l > v) return;
	push(id,l,r);
	if (u <= l && r <= v) {
		lazy1[id] = (lazy1[id] + x)%MOD;
		segtree[id] = (segtree[id] + (r-l+1)*x)%MOD;
		return;
	}
	ll m = (l+r)/2;
	update1(id*2,l,m,u,v,x);
	update1(id*2+1,m+1,r,u,v,x);
	segtree[id] = (segtree[id*2]+segtree[id*2+1])%MOD;
}
void update2(int id, ll l, ll r, ll u, ll v, ll x) {
	if (r < u || l > v) return;
	push(id,l,r);
	if (u <= l && r <= v) {
		lazy2[id] = (lazy2[id]*x)%MOD;
		segtree[id] = (segtree[id]*x)%MOD;
		return;
	}
	ll m = (l+r)/2;
	update2(id*2,l,m,u,v,x);
	update2(id*2+1,m+1,r,u,v,x);
	segtree[id] = (segtree[id*2]+segtree[id*2+1])%MOD;
}
void update3(int id, ll l, ll r, ll u, ll v, ll x) {
	if (r < u || l > v) return;
	push(id,l,r);
	if (u <= l && r <= v) {
		lazy3[id] = x;
		lazy2[id] = 1;
		lazy1[id] = 0;
		segtree[id] = ((r-l+1)*x)%MOD;
		return;
	}
	ll m = (l+r)/2;
	update3(id*2,l,m,u,v,x);
	update3(id*2+1,m+1,r,u,v,x);
	segtree[id] = (segtree[id*2]+segtree[id*2+1])%MOD;
}
ll get(int id, ll l, ll r, ll u, ll v) {
	if (r < u || l > v) return 0;
	push(id,l,r);
	if (u <= l && r <= v) return segtree[id];
	ll m = (l+r)/2;
	return (get(id*2,l,m,u,v) + get(id*2+1,m+1,r,u,v))%MOD;
}
void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			ll l, r, x; cin >> l >> r >> x;
			update1(1,1,n,l,r,x);
		} else if (t == 2) {
			ll l, r, x; cin >> l >> r >> x;
			update2(1,1,n,l,r,x);
		} else if (t == 3) {
			ll l, r, x; cin >> l >> r >> x;
			update3(1,1,n,l,r,x);
		} else {
			ll l, r; cin >> l >> r;
			cout << get(1,1,n,l,r) << endl;
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
