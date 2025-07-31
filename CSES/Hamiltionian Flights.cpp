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
	int n, m; cin >> n >> m;
	vector<int> adjList[n];
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adjList[v].psb(u);
	}
	vector<vector<ll>> dp((1<<n),vector<ll>(n,0));
	dp[1][0] = 1;
	for (int mask = 2; mask < (1 << n); mask++) {
		if (!(mask & (1 << 0))) continue;
		if ((mask & (1 << (n-1)) && mask != ((1 << n)-1))) continue;
		for (int u = 0; u < n; u++) {
			if (!(mask & (1 << u))) continue;
			
			int prev = mask - (1 << u);
			for (int v : adjList[u]) {
				if (!(mask & (1 << v))) continue;
				dp[mask][u] += dp[prev][v];
				dp[mask][u] %= MOD;
			}
		}
	}
	cout << dp[(1 << n) -1][n-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
