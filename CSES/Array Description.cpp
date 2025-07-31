#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<ll>> dp(n,vector<ll>(m+2,0));
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (i == 0) {
			if (x == 0) {
				for (int j = 1; j <= m; j++) dp[i][j] = 1;
			} else dp[i][x] = 1;
		} else {
			if (x == 0) {
				for (int j = 1; j <= m; j++) {
					dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
					dp[i][j] %= mod;
				}
			} else {
				dp[i][x] = dp[i-1][x-1] + dp[i-1][x] + dp[i-1][x+1];
				dp[i][x] %= mod;
			}
		}
	}
	ll kq = 0;
	for (int i = 1; i <= m; i++) {
		kq += dp[n-1][i];
		kq %= mod;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
