#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	//
	int dx[] = {0,1};
	int dy[] = {1,0};
	vector<vector<ll>> dp(n,vector<ll>(n,0));
	dp[n-1][n-1] = 1;
	for (int i = n-1; i >= 0; i--) {
		for (int j = n-1; j >= 0; j--) {
			for (int k = 0; k < 2; k++) {
				int x = i + dx[k], y = j + dy[k];
				if (x < n && y < n) dp[i][j] = (dp[i][j] + dp[x][y])%mod;
			}
		}
	}
	//
	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		cout << dp[u-1][v-1] << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
