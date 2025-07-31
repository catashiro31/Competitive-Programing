#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool BFS(vector<vector<int>>& grid, int n, int low, int high) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;

    if (low <= grid[0][0] && grid[0][0] <= high) {
        q.push({0, 0});
        visited[0][0] = true;
    }

    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();

        if (ux == n - 1 && uy == n - 1) return true;

        for (int i = 0; i < 4; i++) {
            int vx = ux + dx[i], vy = uy + dy[i];
            if (vx >= 0 && vx < n && vy >= 0 && vy < n && !visited[vx][vy]) {
                if (grid[vx][vy] >= low && grid[vx][vy] <= high) {
                    visited[vx][vy] = true;
                    q.push({vx, vy});
                }
            }
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    int cmin = INT_MAX, cmax = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            cmin = min(cmin, grid[i][j]);
            cmax = max(cmax, grid[i][j]);
        }
    }

    int l = 0, r = cmax - cmin, ans = cmax - cmin;
    while (l <= r) {
        int mid = (l + r) / 2;
        bool found = false;

        for (int low = cmin; low + mid <= cmax; low++) {
            if (BFS(grid, n, low, low + mid)) {
                found = true;
                break;
            }
        }

        if (found) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    solve();
    return 0;
}