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
	int n, q; cin >> n >> q;
	map<int,int> c[n];
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int j = 0; j < x; j++) {
			int xx; cin >> xx;
			c[i][xx] = 1;
		}
	}
	while (q--) {
		int k; cin >> k;
		int kq = 0, tmp = 0;
		for (int i = 0; i < n; i++) {
			if (c[i][k]) tmp++;
			else tmp = 0;
			kq = max(kq,tmp);
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
