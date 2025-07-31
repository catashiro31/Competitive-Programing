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
	int n, m; cin >> n >> m;
	vector<string> grid(n);
	for (auto &x : grid) cin >> x;
	bool kq = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '0') continue;
			bool c1 = true, c2 = true;
			for (int k = j-1; k >= 0; k--) {
				if (grid[i][k] == '0') c1 = false;
			}
			for (int k = i-1; k >= 0; k--) {
				if (grid[k][j] == '0') c2 = false;
			}
			kq = (kq && (c1 || c2));
		}
	}
	if (kq) cout << "YES" << endl;
	else cout << "NO" << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	int t; cin >> t;
	while (t--) {
		solve();
	}
}
