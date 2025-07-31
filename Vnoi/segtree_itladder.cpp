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
ll lazy1[MAXN*4], lazy2[MAXN*4], segtree[MAXN*4];
ll modulo = 1;
void push(int id, ll u, ll v, ll m) {
	if (lazy1[id] == 0 && lazy2[id] == 0) return;
	lazy1[id*2] = (lazy1[id*2] + lazy1[id])%MOD;
	lazy1[id*2+1] = (lazy1[id*2+1] + lazy1[id])%MOD;
	lazy2[id*2] = (lazy2[id*2] + lazy2[id])%MOD;
	lazy2[id*2+1] = (lazy2[id*2+1] + lazy2[id])%MOD;
	segtree[id*2] = (segtree[id*2] + ((((m-u+1)*(m+u)*modulo)%MOD)*lazy1[id])%MOD + (m-u+1)*lazy2[id])%MOD;
	segtree[id*2+1] = (segtree[id*2+1] + ((((v-m)*(v+m+1)*modulo)%MOD)*lazy1[id])%MOD + (v-m)*lazy2[id])%MOD;
	lazy1[id] = 0, lazy2[id] = 0;
	return;
}
void update(int id, ll l, ll r, ll u, ll v, ll a, ll b) {
	if (r < u || l > v) return;
	if (u <= l && r <= v) {
		lazy1[id] = (lazy1[id] + a)%MOD;
		lazy2[id] = ((lazy2[id] + (-u*a+b))%MOD+MOD)%MOD; 
		segtree[id] = (segtree[id] + ((((r-l+1)*(r+l)*modulo)%MOD)*a)%MOD + (((r-l+1)*(-u*a+b))%MOD+MOD)%MOD)%MOD;
		return;
	}
	int m = (l+r)/2;
	push(id,l,r,m);
	update(id*2,l,m,u,v,a,b);
	update(id*2+1,m+1,r,u,v,a,b);
	segtree[id] = (segtree[id*2] + segtree[id*2+1])%MOD;
	return;
}
ll get(int id, ll l , ll r, ll u, ll v) {
	if (r < u || l > v) return 0;
	if (u <= l && r <= v) return segtree[id];
	int m = (l+r)/2;
	push(id,l,r,m);
	ll tmp1 = get(id*2,l,m,u,v);
	ll tmp2 = get(id*2+1,m+1,r,u,v);
	return (tmp1+tmp2)%MOD;
}
void solve() {
	memset(segtree,0,sizeof(segtree));
	memset(lazy1,0,sizeof(lazy1));
	memset(lazy2,0,sizeof(lazy2));
	ll base = 2, i = MOD-2;
	while (i) {
		if (i%2) modulo = (modulo*base)%MOD;
		base = (base*base)%MOD;
		i/=2;
	}
	int n, q; cin >> n >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			ll l,r,a,b; cin >> l >> r >> a >> b;
			update(1,1,n,l,r,a,b);
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
