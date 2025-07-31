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
	vector<bool> c(1e7+1,false);
	c[0] = true, c[1] = true;
	vector<int> snt;
	for (int i = 0; i <= 1e7; i++) {
		if (c[i]) continue;
		snt.psb(i);
		for (ll j = 1LL*i*i; j <= 1e7; j+=i) c[j] = true;
	}
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int kq = 0;
		for (int i = 1; i <= n; i++) {
			auto it = ub(all(snt),n/i);
			if (it == snt.begin()) break;
			kq += (it-snt.begin());
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
