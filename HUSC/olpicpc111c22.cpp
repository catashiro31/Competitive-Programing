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
int n, m;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(pair<int,int> u, char prv,  vector<vector<int>> &dp, const vector<string> &color_row, const vector<string> &color_col) {
	cout << prv << endl;
	deque<tuple<int,int,char>> dq;
	for (int k = 0; k < 4; k++) {
		int nx = dx[k] + u.fi, ny = dy[k] + u.se;
		if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
		if (dp[nx][ny] <= dp[u.fi][u.se]) continue;
		char tp;
		if (k == 0) tp = color_col[u.fi-1][ny];
		else if (k == 2) tp = color_col[u.fi][ny];
		else if (k == 1) tp = color_row[nx][u.se];
		else tp = color_row[nx][u.se-1];
		if (tp == prv) dq.push_front({nx,ny,tp});
		else dq.push_back({nx,ny,tp});
	}
	while (!dq.empty()) {
		auto [nx,ny,tp] = dq.front(); dq.pop_front();
		if (tp == prv) dp[nx][ny] = dp[u.fi][u.se];
		else dp[nx][ny] = dp[u.fi][u.se] + 1;
		dfs({nx,ny},tp,dp,color_row,color_col);
	}
	cout << endl;
}

void solve() {
	cin >> n >> m;
	vector<string> color_row(n), color_col(n-1);
	for (int i = 0; i < n; i++) cin >> color_row[i];
	for (int i = 0; i < n-1; i++) cin >> color_col[i];
	int q; cin >> q;
	while (q--) {
		pair<int,int> src, dst; cin >> src.fi >> src.se >> dst.fi >> dst.se;
		--src.fi, --src.se, --dst.fi, --dst.se;
		vector<vector<int>> dp(n,vector<int>(m,LLONG_MAX));
		dp[src.fi][src.se] = 0;
		dfs(src,'-',dp,color_row,color_col);	
		cout << dp[dst.fi][dst.se] << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
