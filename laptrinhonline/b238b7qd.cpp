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

void solve() {
	int n, q; cin >> n >> q;
	ll a[n+1];
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<ll> prefix(n+1,0);
	for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i];
	while (q--) {
		int l, r; cin >> l >> r;
		ll sum = prefix[r] - prefix[l-1];
		sum /= 2;
		int i = lb(prefix.begin()+1,prefix.end(),prefix[l-1]+sum) - prefix.begin();
		int j = lb(prefix.begin()+1,prefix.end(),prefix[i-1]) - prefix.begin();
		int k = ub(prefix.begin()+1,prefix.end(),prefix[l-1]+sum) - prefix.begin();
		ll cmin = LLONG_MAX;
		int kq = INT_MAX;
		if (l <= i && i < r) {
			ll tmp = abs((prefix[r]-prefix[i])-(prefix[i]-prefix[l-1]));
			if (tmp < cmin) cmin = tmp, kq = i;
			if (tmp == cmin) kq = min(kq,i);
		}
		if (l <= j && j < r) {
			ll tmp = abs((prefix[r]-prefix[j])-(prefix[j]-prefix[l-1]));
			if (tmp < cmin) cmin = tmp, kq = j;
			if (tmp == cmin) kq = min(kq,j);
		}
		if (l <= k && k < r) {
			ll tmp = abs((prefix[r]-prefix[k])-(prefix[k]-prefix[l-1]));
			if (tmp < cmin) cmin = tmp, kq = k;
			if (tmp == cmin) kq = min(kq,k);
		}
		cout << kq << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}