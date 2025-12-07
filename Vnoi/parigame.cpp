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
	vector<vector<int>> a(n+1,vector<int>(n+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	vector<vector<int>> prefix_row(n+1,vector<int>(n+1,0)), prefix_col(n+1,vector<int>(n+1,0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			prefix_row[i][j] = (prefix_row[i][j-1] + a[i][j]) & 1;
			prefix_col[i][j] = (prefix_col[i-1][j] + a[i][j]) & 1; 
		}
	}
	vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = (prefix_row[i][j] == 0 ? !dp[i-1][j] : 0) || (prefix_col[i][j] == 0 ? !dp[i][j-1] : 0);
		}
	}
	if (dp[n][n]) cout << "YES" << endl;
	else cout << "NO" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
