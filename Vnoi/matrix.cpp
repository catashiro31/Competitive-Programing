#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void updateAns(int val, int cntAns, int &kq, int &cnt) {
	if (val > kq) { kq = val; cnt = cntAns; }
	else if (val == kq) cnt += cntAns;
}

void solve() {
	int m, n; cin >> m >> n;
	vector<vector<int>> grid(m+1,vector<int>(n+1));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) cin >> grid[i][j];
	}
	vector<vector<int>> row(m+1,vector<int>(n+1, 0)), col(m+1,vector<int>(n+1,0));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			row[i][j] = row[i][j-1] + grid[i][j];
			col[i][j] = col[i-1][j] + grid[i][j]; 
		}
	}
	int ans = -m*n, cnt = 0;
	for (int i = 1; i <= m; i++) {
		for (int l = 0; l < n; l++) {
			for (int r = l+1; r <= n; r++) {
				updateAns(2LL*(row[i][r]-row[i][l])-(r-l),1,ans,cnt);
			}
		}
	}
	for (int d = 0; d < m; d++) {
		for (int u = d+2; u <= m; u++) {
			int maxcol = -m*n, cntcol = 0;
			for (int j = 1; j <= n; j++) {
				int cur = (col[u][j] - col[d][j])*2 - (u-d);
				int side = (grid[u][j]+grid[d+1][j])*2 - 2;
				updateAns(cur, 1, ans, cnt);
				updateAns(cur + maxcol, cntcol, ans, cnt);
				maxcol += side;
                if (cur > maxcol) {
                    maxcol = cur;
                    cntcol = 1;
                } else cntcol += (cur == maxcol);
			}
		}
	}
	cout << ans << " " << cnt << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
