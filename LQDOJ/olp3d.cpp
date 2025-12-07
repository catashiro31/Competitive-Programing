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
	int m, n, k, s; cin >> m >> n >> k >> s;
	vector<vector<int>> grid(m+5,vector<int>(n+5,0));
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <= x2; j++) grid[j][y1]++, grid[j][y2+1]--;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) grid[i][j] = grid[i][j-1] + grid[i][j];
	}
	vector<vector<int>> prefix2D(m+5,vector<int>(n+5,0));
	int kq = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			prefix2D[i][j] = prefix2D[i-1][j] + prefix2D[i][j-1] - prefix2D[i-1][j-1];
			if (grid[i][j] == s) kq++, prefix2D[i][j]--;
			else if (grid[i][j] == s-1) prefix2D[i][j]++;
		}
	}
	int cmax = LLONG_MIN;
	for (int i = 1; i < m; i++) {
		for (int j = i; j <= m; j++) {
			int cmin = 0;
			for (int k = 1; k <= n; k++) {
				int val = prefix2D[j][k] - prefix2D[i-1][k];
				cmax = max(cmax, val-cmin);
				cmin = min(cmin, val);
			}
		}
	}
	if (cmax == LLONG_MIN) cout << 0 << endl;
	else cout << kq+cmax;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
