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
	vector<ll> a(n);
	for (ll &x : a) cin >> x;
	vector<ll> prefix(n);
	for (int i = 0; i < n; i++) {
		if (i == 0) prefix[i] = a[i];
		else prefix[i] = prefix[i-1] + a[i];
	}
	vector<vector<ll>> dp(n,vector<ll>(n,LLONG_MAX));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i; j++) {
			if (i == 0) dp[j][j+i] = 0;
			else {
				ll sum = prefix[j+i];
				if (j > 0) sum -= prefix[j-1];
				for (int k = j; k < j+i; k++) {
					dp[j][j+i] = min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]+sum);
				}
			}
		}
	}
	cout << dp[0][n-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
