#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3;
int dx[8] = {0, 0, -1, -1, -1, 1, 1, 1};
int dy[8] = {1, -1, 0, 1, -1, 0, -1, 1};
int n, m;
int board[MAX][MAX];
bool visited[MAX][MAX];
bool IsHill;

void DFS(int x, int y) {
    visited[x][y] = true;
    for (int k = 0; k < 8; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (board[nx][ny] > board[x][y]) IsHill = false;
            if (board[nx][ny] == board[x][y] && !visited[nx][ny]) DFS(nx, ny);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            visited[i][j] = false;
        }
    int res = 0;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j]) {
                IsHill = true;
                DFS(i, j);
                if (IsHill) res++;
            }
        }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}