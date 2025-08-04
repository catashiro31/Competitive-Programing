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
const string NoF = "Name_of_File";
ll fact[MAXN], inv[MAXN];
ll inv_modulo(ll base, ll exp) {
	ll res = 1;
	while (exp) {
		if (exp&1) res = (res * base) % MOD;
		base = (base * base) % MOD;
		exp /= 2;
	}
	return res;
}
ll combination(ll n, ll k) {
	if (k > n || k < 0 || n < 0) return 0;
	ll res = fact[n];
	res = (res * inv[k]) % MOD;
	res = (res * inv[n-k]) % MOD;
	return res;
}
void init(void) {
	fact[0] = 1, inv[0] = inv_modulo(fact[0],MOD-2);
	for (int i = 1;  i < MAXN; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
		inv[i] = inv_modulo(fact[i],MOD-2);
	}
}
void solve() {
	int m, n, k; cin >> m >> n >> k;
	vector<vector<bool>> blocked(1e3+3, vector<bool>(1e3+3, false));
	int maxr = 1, maxc = 1;
	for (int i = 0; i < k; i++) {
		int r, c; cin >> r >> c;
		blocked[r][c] = true;
		maxr = max(maxr,r);
		maxc = max(maxc,c);
	}
	init();
	vector<vector<ll>> dp(maxr+1, vector<ll>(maxc+1,0));
	dp[1][1] = 1;
	for (int i = 1; i <= maxr; i++) {
		for (int j = 1; j <= maxc; j++) {
			if (i == 1 && j == 1) continue;
			if (blocked[i][j]) continue;
			dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
		}
	}
	if (m == maxr && n == maxc) cout << dp[maxr][maxc];
	else {
		ll kq = 0;
		for (int i = 1; i <= maxr; i++) {
			ll value = (dp[i][maxc] * combination(m-i + n-maxc-1, m-i)) % MOD;
			kq = (kq + value) % MOD;
		}
		for (int j = 1; j <= maxc; j++) {
			ll value = (dp[maxr][j] * combination(m-maxr-1 + n-j, n-j)) % MOD;
			kq = (kq + value) % MOD;
		}
		cout << kq;
	}
}
	
int main() {
#ifndef ONLINE_JUDGE
	// freopen((NoF + ".in").c_str(), "r", stdin);
	// freopen((NoF + ".out").c_str(), "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	while(t--) {
		solve();
	}
}