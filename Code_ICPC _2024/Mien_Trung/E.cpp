#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX_R = 100;
const int MAX_C = 100;
const int MAX_N = 15;
const int INF = 1e9;

int R, C, N;
char grid[MAX_R][MAX_C + 1];
vector<pair<int, int>> vts;  
int dist[MAX_N + 1][MAX_N + 1];   

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int idx, vector<vector<int>>& f_dis) {
    vector<vector<int>> distance(R, vector<int>(C, INF));
    queue<pair<int, int>> q;
    int sx = vts[idx].first;
    int sy = vts[idx].second;
    distance[sx][sy] = 0;
    q.push({sx, sy});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (grid[nx][ny] == '#') continue;

            if (distance[nx][ny] == INF) {
                distance[nx][ny] = distance[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < vts.size(); ++i) {
        int tx = vts[i].first;
        int ty = vts[i].second;
        f_dis[idx][i] = distance[tx][ty];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> N;
    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
    }

    vector<pair<int, int>> shr;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 'S') {
                shr.push_back({i, j});
            }
        }
    }

    if (shr.size() != N) {
        cout << -1 << '\n';
        return 0;
    }

    int start_x = 0;
    int start_y = 0;
    vts = shr;
    vts.push_back({start_x, start_y}); 

    int tol_N = N + 1;

    vector<vector<int>> f_dis(tol_N, vector<int>(tol_N, INF));

    for (int i = 0; i < tol_N; ++i) {
        bfs(i, f_dis);
    }

    for (int i = 0; i < tol_N; ++i) {
        for (int j = 0; j < tol_N; ++j) {
            if (f_dis[i][j] == INF) {
                if (i == tol_N - 1 || j == tol_N - 1 || (i < N && j < N)) {
                    continue;
                } else {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }

    int full_mask = (1 << N) - 1;
    vector<vector<int>> DP(1 << N, vector<int>(N, INF));

    for (int i = 0; i < N; ++i) {
        int dist_to_i = f_dis[N][i];
        if (dist_to_i != INF) {
            DP[1 << i][i] = dist_to_i;
        }
    }

    for (int mask = 0; mask <= full_mask; ++mask) {
        for (int u = 0; u < N; ++u) {
            if (!(mask & (1 << u))) continue;  
            if (DP[mask][u] == INF) continue;

            for (int v = 0; v < N; ++v) {
                if (mask & (1 << v)) continue;  
                int checn_nex = mask | (1 << v);
                int cost = f_dis[u][v];
                if (cost != INF && DP[checn_nex][v] > DP[mask][u] + cost) {
                    DP[checn_nex][v] = DP[mask][u] + cost;
                }
            }
        }
    }

    int min_steps = INF;
    for (int u = 0; u < N; ++u) {
        if (DP[full_mask][u] != INF) {
            min_steps = min(min_steps, DP[full_mask][u]);
        }
    }

    if (min_steps == INF) {
        cout << -1 << '\n';
    } else {
        cout << min_steps << '\n';
    }

    return 0;
}