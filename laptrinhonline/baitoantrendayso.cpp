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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), bit(n,0);
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			a[i] = x;
			while (x) {
				int m = x%10;
				bit[i] |= (1 << m);
				x /= 10;
			}
		}
		vector<int> dp((1<<10),INT_MIN);
		dp[0] = 0;
		for (int mask = 0; mask < (1<<10); mask++) {
			if (dp[mask] == INT_MIN) continue;
			for (int i = 0; i < n; i++) {
				if ((mask & bit[i]) == 0) {
					dp[mask | bit[i]] = max(dp[mask | bit[i]], dp[mask] + a[i]);
				}
			}
		}
		cout << *max_element(all(dp)) << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
