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
ll dp[MAXN], a[MAXN];
vector<ll> segtree(MAXN*4,LLONG_MIN);
void update(int id, int l, int r, int p, ll val) {
	if (p < l || p > r) return;
	if (l == r) {
		segtree[id] = val;
		return;
	}
	int m = (l+r)/2;
	update(id*2,l,m,p,val);
	update(id*2+1,m+1,r,p,val);
	segtree[id] = max(segtree[id*2],segtree[id*2+1]);
}
ll get(int id, int l, int r, int u, int v) {
	if (v < l || u > r) return LLONG_MIN;
	if (u <= l && r <= v) return segtree[id];
	int m = (l+r)/2;
	ll tmp1 = get(id*2,l,m,u,v);
	ll tmp2 = get(id*2+1,m+1,r,u,v);
	return max(tmp1,tmp2);
}
void solve() {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		dp[i] = max(get(1,1,n,i-k,i-1),0LL) + a[i];
		update(1,1,n,i,dp[i]);
	}
	ll kq = 0;
	for (int i = 1; i <= n; i++) kq = max(kq,dp[i]);
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
