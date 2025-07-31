#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
void solve() {
	int t; cin >> t;
	while(t--) {
		int R, C; cin >> R >> C;
		int r, c; cin >> r >> c;
		--r, --c;
		vector<string> maze(R);
		vector<pair<int,int>> key;
		for (int i = 0; i < R; i++) {
			cin >> maze[i];
			for (int j = 0; j < C; j++) {
				if (maze[i][j] == 'a') key.pb({i,j});
			}
		}
		vector<vector<int>> dp1(R,vector<int>(C,-1));
		queue<pair<int,int>> q;
		q.push({r,c});
		dp1[r][c] = 0;
		int kq = INT_MAX;
		while (!q.empty()) {
			int u = q.front().fi, v = q.front().se; 
			q.pop();
			for (int i = 0; i < 4; i++) {
				int x = u + dx[i], y = v + dy[i];
				if (maze[x][y] == 'X' || maze[x][y] == 'A' || dp1[x][y] != -1) continue;
				dp1[x][y] = dp1[u][v] + 1;
				if (maze[x][y] == 'O') kq = min(kq,dp1[x][y]);
				q.push({x,y});
			}
		}
		if (kq == INT_MAX) {
			vector<vector<int>> dp2(R,vector<int>(C,INT_MAX));
			for (pair<int,int> k : key) {
				int x = k.fi, y = k.se;
				if (dp1[x][y] != -1) {
					dp2[x][y] = dp1[x][y];
					q.push({x,y});
				}
			}
			while (!q.empty()) {
				int u = q.front().fi, v = q.front().se; 
				q.pop();
				for (int i = 0; i < 4; i++) {
					int x = u + dx[i], y = v + dy[i];
					if (maze[x][y] == 'X' || dp2[u][v] + 1 >= dp2[x][y]) continue;
					dp2[x][y] = dp2[u][v] + 1;
					if (maze[x][y] == 'O') kq = min(kq,dp2[x][y]); 
					q.push({x,y});
				}
			}
		}
		if (kq == INT_MAX) cout << -1 << " ";
		else cout << kq << " ";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
