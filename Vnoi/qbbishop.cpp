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
	int n, m, p, q, s, t; cin >> n >> m >> p >> q >> s >> t;
	vector<vector<int>> board(n+1,vector<int>(n+1,0));
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		board[x][y] = 1;
	}
	vector<vector<int>> vis(n+1,vector<int>(n+1,LLONG_MAX));
	queue<pair<int,int>> qe;
	qe.push({p,q}); vis[p][q] = 0;
	int dx[4] = {1,-1,-1,1};
	int dy[4] = {1,-1,1,-1};
	
	while (!qe.empty()) {
		auto [x,y] = qe.front(); qe.pop();
		if (x == s && y == t) {
			cout << vis[x][y] << endl;
			return;
		}
		for (int k = 0; k < 4; k++) {
			for (int i = 1; i <= n; i++) {
				int nx = dx[k]*i + x, ny = dy[k]*i + y;
				if (nx <= 0 || n < nx || ny <= 0 || n < ny) continue;
				if (board[nx][ny]) break;
				if (vis[nx][ny] != LLONG_MAX) continue;
				vis[nx][ny] = min(vis[nx][ny], vis[x][y] + 1);
				qe.push({nx,ny});
			}
		}
	}
	cout << -1 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
