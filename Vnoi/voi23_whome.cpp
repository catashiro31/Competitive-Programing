#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define psb push_back
#define ppb pop_back
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
const string NoF = "WHOME";

void solve() {
	ll n, m, p, c; cin >> n >> m >> p >> c;
	vector<ll> a(n), s(m);
	for (ll &x : a) cin >> x;
	for (ll &x : s) cin >> x;
	vector<vector<ll>> dp(n+1, vector<ll>(1<<m,LLONG_MIN));
	sort(all(a));
	dp[0][0] = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j < m; j++) {
			if (i - s[j] < 0) continue;
			for (ll mask = 0; mask < (1<<m); mask++) {
				if (dp[i-s[j]][mask] == LLONG_MIN) continue;
				dp[i][mask|(1<<j)] = max(dp[i][mask|(1<<j)], dp[i-s[j]][mask] + p - (a[i-1]-a[i-s[j]])*(a[i-1]-a[i-s[j]])*c);
			}
		}
		for (ll mask = 0; mask < (1<<m); mask++) dp[i][mask] = max(dp[i][mask], dp[i-1][mask]);
	}
	cout << dp[n][(1<<m)-1];
}

int main() {
//    freopen((NoF + ".INP").c_str(), "r", stdin);
//    freopen((NoF + ".OUT").c_str(), "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}
