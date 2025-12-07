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
	string up, dw; cin >> up >> dw;
	int n = sz(up);
	vector<vector<int>> dp(n,vector<int>(2,0));
	if (up[0] == 'X') dp[0][0] = 1;
	if (dw[0] == 'X') dp[0][1] = 1;
	for (int i = 1; i < n; i++) {
		if (up[i] == 'X') dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD;
		if (dw[i] == 'X') dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % MOD;
	}
	cout << (dp[n-1][0] + dp[n-1][1]) % MOD << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
