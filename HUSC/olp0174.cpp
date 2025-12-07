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
	vector<vector<int>> board(n,vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> board[i][j];
	}
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
	vector<vector<int>> vis(n,vector<int>(m,false));
	for (int i = 0; i < n; i++) {
		vis[i][0] = true;
		pq.push({board[i][0],{i,0}});
		vis[i][m-1] = true;
		pq.push({board[i][m-1],{i,m-1}});
	}
	for (int j = 0; j < m; j++) {
		vis[0][j] = true;
		pq.push({board[0][j],{0,j}});
		vis[n-1][j] = true;
		pq.push({board[n-1][j],{n-1,j}});
	}
	int ans = 0;
	int di[] = {-1, 1, 0, 0};
	int dj[] = {0, 0, -1, 1};
	while (!pq.empty()) {
		auto [v,ij] = pq.top(); pq.pop();
		auto [i,j] = ij;
		for (int k = 0; k < 4; k++) {
			int ni = i + di[k], nj = j + dj[k];
			if (ni < 0 || nj < 0 || ni >= n || nj >= m || vis[ni][nj]) continue;
			vis[ni][nj] = 1;
			if (board[ni][nj] < v) ans += (v-board[ni][nj]);
			int nv = max(v,board[ni][nj]);
			pq.push({nv,{ni,nj}});
		}
	}
	cout << ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
