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

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<ll> a(n);
	for (ll &x : a) cin >> x;
	vector<pair<pair<int,int>,ll>> upd(m);
	for (int i = 0; i < m; i++) {
		cin >> upd[i].fi.fi >> upd[i].fi.se >> upd[i].se;
		upd[i].fi.fi--;
	}
	vector<ll> query(m,0);
	for (int i = 0; i < k; i++) {
		int l, r; cin >> l >> r;
		--l;
		query[l]++;
		if (r < m) query[r]--;
	}
	for (int i = 1; i < m; i++) query[i] += query[i-1];
	vector<ll> add(n,0);
	for (int i = 0; i < m; i++) {
		add[upd[i].fi.fi] += query[i]*upd[i].se;
		if (upd[i].fi.se < n) add[upd[i].fi.se] -= query[i]*upd[i].se; 
	}
	for (int i = 1; i < n; i++) add[i] += add[i-1];
	for (int i = 0; i < n; i++) cout << a[i] + add[i] << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
