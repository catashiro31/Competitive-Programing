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
vector<ll> BIT(MAXN,0);
void update(int id, ll val) {
	while (id < MAXN) {
		BIT[id] = max(BIT[id],val);
		id += (id & (-id)); 
	}
}
ll query(int id) {
	ll ans = LLONG_MIN;
	while (id) {
		ans = max(ans,BIT[id]);
		id -= (id & (-id));
	}
	return ans;
}
void solve() {
	int n; cin >> n;
	vector<ll> h(n), a(n);
	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 0; i < n; i++) cin >> a[i];
	ll kq = LLONG_MIN;
	for (int i = 0; i < n; i++) {
		ll tmp = query(h[i]) + a[i]; 
		kq = max(kq,tmp);
		update(h[i]+1,tmp);
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
