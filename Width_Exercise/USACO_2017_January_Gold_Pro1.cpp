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
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 2e5+1;
const int MOD = 1e9+7;
const string NoF = "bphoto";

void solve() {
	int n; cin >> n;
	vector<int> h(n);
	for (int &x : h) cin >> x;
	OST<int> ost_l, ost_r;
	for (int x : h) ost_r.insert(x);
	int kq = 0;
	for (int i = 0; i < n; i++) {
		ost_r.erase(h[i]);
		int l = i - ost_l.order_of_key(h[i]);
		int r = sz(ost_r) - ost_r.order_of_key(h[i]);
		if (l*2 < r || r*2 < l) kq++;
		ost_l.insert(h[i]);
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen((NoF + ".in").c_str(),"r",stdin);
	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
