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
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	s = " " + s, t = " " + t;
	int k; cin >> k;
	int kq1 = 0;
	for (int i = 1; i+m-1 <= n; i++) {
		bool c = true;
		for (int j = 1; j <= m; j++) {
			if (s[i+j-1] != t[j]) c = false;
		}
		if (c) kq1++;
	}
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i][j-1];
			if (s[j] != t[i]) continue;
			if (i == 1) dp[i][j] = (dp[i][j] + 1) % MOD;
			else dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
		}
	}
	int kq2 = dp[m][n];
	if (k == 1) cout << kq1 << endl;
	else cout << kq2 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
