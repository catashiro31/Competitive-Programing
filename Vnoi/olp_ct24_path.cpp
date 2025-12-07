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

//int inv(int base, int exp) {
//	int res = 1;
//	while(exp) {
//		if (exp&1) res = (res * base) % MOD;
//		base = (base * base) % MOD;
//		exp /= 2;
//	}
//	return res;
//}

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> dp(1001,vector<int>(1001,0));
	dp[0][0] = 1;
	vector<vector<bool>> block(1001,vector<bool>(1001,false));
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		--x, --y;
		block[x][y] = true;
	}
	int dx[] = {-1,0};
	int dy[] = {0,-1};
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			if (block[i][j]) continue;
			for (int z = 0; z < 2; z++) {
				int nx = dx[z] + i, ny = dy[z] + j;
				if (nx < 0 || ny < 0) continue;
				dp[i][j] = (dp[i][j] + dp[nx][ny]) % MOD;
			}
		}
	}
	if (n <= 1000 && m <= 1000) cout << dp[n-1][m-1];
	else {
		vector<int> exp2(1e5+5);
		exp2[0] = 1;
		for (int i = 1; i < 1e5+5; i++) exp2[i] = (exp2[i-1] * 2) % MOD;
		int kq = 0;
		if (n > 1000) {
			for (int j = 0; j < min(m,1000LL); j++) {
				int d = (m-1-j) + (n-1-999);
				kq = (kq+dp[999][j]*exp2[d]) % MOD;
			}
		}
		if (m > 1000) {
			for (int j = 0; j < min(1000LL,n); j++) {
				int d = (m-1-999) + (n-1-j);
				kq = (kq+dp[j][999]*exp2[d]) % MOD;
			}
		}
		cout << kq;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
