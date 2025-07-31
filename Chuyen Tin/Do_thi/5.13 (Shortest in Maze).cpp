#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int m, n;
pair<int, vector<pair<int, int>>> BFS(vector<vector<char>>& maze, pair<int, int> start) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    map<pair<int, int>, pair<int, int>> parent;
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    parent[start] = {-1, -1}; 
    while (!q.empty()) {
        pair<int, int> pos = q.front(); q.pop();
        if (pos.first == 0 || pos.first == m-1 || pos.second == 0 || pos.second == n-1) {
            vector<pair<int, int>> path;
            pair<int, int> current = pos;
            while (current != make_pair(-1, -1)) {
                path.push_back(current);
                current = parent[current];
            }
            reverse(path.begin(), path.end()); 
            return {path.size() - 1, path};  
        }
        for (int i = 0; i < 4; ++i) {
            int ny = pos.first + dy[i];
            int nx = pos.second + dx[i];

            if (ny >= 0 && ny < m && nx >= 0 && nx < n && !visited[ny][nx] && maze[ny][nx] == 'O') {
                visited[ny][nx] = true;
                q.push({ny, nx});
                parent[{ny, nx}] = pos; 
            }
        }
    }
    return {-1, {}};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
    inFile >> m >> n;
    vector<vector<char>> maze(m, vector<char>(n));
    pair<int, int> start;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            inFile >> maze[i][j];
            if (maze[i][j] == 'E') {
                start = {i, j};
            }
        }
    }
	inFile.close();
    auto result = BFS(maze, start);
    if (result.first == -1) {
        cout << "Khong co duong thoat" << '\n';
    } else {
        cout << "Do dai duong di ngan nhat: " << result.first << '\n';
        cout << "Duong di: ";
        for (auto p : result.second) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << '\n';
    }
    return 0;
}

