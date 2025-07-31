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
	int n, k, q; cin >> n >> k >> q;
	vector<ll> add(2e5+1,0);
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		add[a]++; 
		if (b+1 <= 2e5) add[b+1]--;
	}
	for (int i = 2; i <= 2e5; i++) add[i] += add[i-1];
	vector<ll> kq(2e5+1,0);
	for (int i = 1; i <= 2e5; i++) {
		if (add[i] >= k) kq[i] = 1;
	}
	for (int i = 2; i <= 2e5; i++) kq[i] += kq[i-1];
	while (q--) {
		int a, b; cin >> a >> b;
		cout << kq[b] - kq[a-1] << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
