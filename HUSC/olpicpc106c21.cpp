#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int n; cin >> n;
	vector<int> w(n+1), v(n+1);
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	int q; cin >> q;
	if (q <= 10 && n <= 20) {
		while (q--) {
			int l, r, z; cin >> l >> r >> z;
			int cnt = r-l+1, kq = 0;
			for (int mask = 1; mask < (1<<cnt); mask++) {
				int weight = 0, val = 0;
				for (int i = 0; i < cnt; i++) {
					if ((mask >> i) & 1) weight += w[l+i], val += v[l+i];
				}
				if (weight <= z) kq = max(kq,val);
			}
			cout << kq << endl;;
		}
		return;
	} else if (q <= 10) {
		while (q--) {
			int l, r, z; cin >> l >> r >> z;
			vector<int> dp(z+5,-1);
			dp[0] = 0;
			for (int i = l; i <= r; i++) {
				for (int j = z; j >= w[i]; j--) {
					if (dp[j-w[i]] == -1) continue;
					dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
				}
			}
			int kq = 0;
			for (int j = z; j >= 0; j--) kq = max(kq,dp[j]);
			cout << kq << endl;
		}
		return;
	}
	vector<vector<int>> dp(n+1,vector<int>(505,-1));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 500; j >= 0; j--) {
			dp[i][j] = dp[i-1][j];
			if (dp[i-1][j-w[i]] == -1 || j < w[i]) continue;
			dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
		}
	}
	while (q--) {
		int l, r, z; cin >> l >> r >> z;
		int kq = 0;
		for (int i = z; i >= 0; i--) kq = max(kq,dp[r][i]);
		cout << kq << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
