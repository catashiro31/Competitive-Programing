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
vector<vector<int>> board(8,vector<int>(8));
int kq = 0;
vector<vector<bool>> used(8,vector<bool>(8,false));
vector<int> row(8,0), col(8,0);
vector<int> chinh(15,0), phu(15,0);
vector<pair<int,int>> stored;
void backtracking(int u) {
	if (u == 4) {
		vector<bool> rused(8,false), cused(8,false), chinhu(15,false), phuu(15,false);
		vector<vector<bool>> bused(8,vector<bool>(8,false));
		int sum = 0;
		rused[stored[0].fi] = true, cused[stored[0].se] = true, chinhu[stored[0].fi+8-stored[0].se] = true;
		phuu[stored[0].fi+stored[0].se+1] = true;
		rused[stored[1].fi] = true, cused[stored[1].se] = true;
		chinhu[stored[2].fi+8-stored[2].se] = true, phuu[stored[2].fi+stored[2].se+1] = true;
		int dx[] = {-1,-1,2,2,1,1,-2,-2};
		int dy[] = {2,-2,-1,1,2,-2,1,-1};
		for (int z = 0; z < 8; z++) {
			int x = stored[3].fi + dx[z], y = stored[3].se + dy[z];
			if (x < 0 || x >= 8 || y < 0 || y >= 8) continue;
			bused[x][y] = true;
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (rused[i] || cused[j] || chinhu[i+8-j] || phuu[i+j+1] || bused[i][j]) sum += board[i][j];
			}
		}
		kq = max(kq, sum);
		return;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (used[i][j]) continue;
			stored.psb({i,j});
			used[i][j] = true;
			backtracking(u+1);
			used[i][j] = false;
			stored.pop_back();
		}
	}
}

void solve() {
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		int r, c, t; cin >> r >> c >> t;
		--r, --c;
		board[r][c] = t;
	}
	for (int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			row[i] += board[i][j];
			col[j] += board[i][j];
			phu[i+j-1] += board[i][j];
			chinh[8-j+i] += board[i][j];
		}
	}
	backtracking(0);
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
