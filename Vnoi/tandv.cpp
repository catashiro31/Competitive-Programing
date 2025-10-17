#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<string> board(n);
	for (string &x : board) cin >> x;
	pair<int,int> viking, you;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'V') viking = {i,j};
			else if (board[i][j] == 'Y') you = {i,j};
		}
	}
	vector<vector<int>> viking_shout(n,vector<int>(m,INT_MAX));
	viking_shout[viking.first][viking.second] = 0;
	queue<pair<int,int>> q;
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	auto check = [&] (int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m;	
	};
	auto shout = [&] (int x, int y, int val) {
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			while (check(nx,ny) && board[nx][ny] != 'I') {
				viking_shout[nx][ny] = min(viking_shout[nx][ny], val);
				nx = nx + dx[k], ny = ny + dy[k];
			}
		}
	};
	vector<vector<int>> viking_go(n, vector<int>(m,-1));
	viking_go[viking.first][viking.second] = 0;
 	for (int k = 0; k < 4; k++) {
 		auto [x,y] = viking;
		if (check(dx[k]+x, dy[k]+y) && board[dx[k]+x][dy[k]+y] != 'I') {
			viking_go[dx[k]+x][dy[k]+y] = 1;
			viking_shout[dx[k]+x][dy[k]+y] = 1;
			q.push({dx[k]+x, dy[k]+y});
		}
	}
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		shout(x,y,viking_go[x][y]);
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (check(nx,ny) && board[nx][ny] != 'I' && viking_go[nx][ny] == -1) {
				viking_go[nx][ny] = viking_go[x][y] + 1;
				q.push({nx,ny});
			}
		}
	}
	vector<vector<int>> you_go(n, vector<int>(m,-1));
	you_go[you.first][you.second] = 0;
	for (int k = 0; k < 4; k++) {
		auto [x,y] = you;
		int nx = dx[k] + x, ny = dy[k] + y;
		if (check(nx, ny) && board[nx][ny] != 'I') {
			you_go[nx][ny] = you_go[x][y] + 1;
			q.push({nx, ny});
		}
	}
	while (!q.empty()) {
		auto [x,y] = q.front(); q.pop();
		if (you_go[x][y] >= viking_shout[x][y]) continue;
		if (board[x][y] == 'T') {
			cout << "YES" << endl;
			return 0;
		}
		for (int k = 0; k < 4; k++) {
			int nx = dx[k] + x, ny = dy[k] + y;
			if (check(nx,ny) && you_go[nx][ny] == -1 && board[nx][ny] != 'I') {
				you_go[nx][ny] = you_go[x][y] + 1;
				q.push({nx,ny});
			}
		}
	}
	cout << "NO" << endl;
}