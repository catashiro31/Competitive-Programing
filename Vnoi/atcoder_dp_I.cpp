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
	int n; cin >> n;
	vector<vector<ll>> dp(n+1,vector<ll>(1<<n,0));
	int grid[n+1][n+1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> grid[i][j];
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int mask = 0; mask < 1<<n; mask++) {
			if (!dp[i-1][mask]) continue;
			for (int j = 1; j <= n; j++) {
				if (!grid[i][j] || mask & 1 << (j-1)) continue;
				dp[i][mask | 1<<(j-1)] = (dp[i][mask | 1<<(j-1)]+dp[i-1][mask])%MOD;
			}
		}
	}
	cout << dp[n][(1<<n)-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
