#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200200;
vector<int> adjList[MAXN];
int depth[MAXN];
int ancestor[MAXN][19];
int flagArr[MAXN]; // nhóm của mỗi node

void dfs(int u, int parent) {
    ancestor[u][0] = parent;
    for (int i = 1; i < 19; i++) {
        int prev = ancestor[u][i-1];
        ancestor[u][i] = (prev == -1 ? -1 : ancestor[prev][i-1]);
    }
    for (int v : adjList[u]) {
        if (v == parent) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 18; i >= 0; i--) {
        if (diff & (1 << i)) u = ancestor[u][i];
    }
    if (u == v) return u;
    for (int i = 18; i >= 0; i--) {
        if (ancestor[u][i] != -1 && ancestor[u][i] != ancestor[v][i]) {
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }
    return ancestor[u][0];
}

int distanceNodes(int u, int v) {
    int w = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[w];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int root = -1;
    // Khởi tạo
    for (int i = 0; i < n; i++) {
        adjList[i].clear();
        depth[i] = 0;
        flagArr[i] = 0;
        for (int j = 0; j < 19; j++) ancestor[i][j] = -1;
    }
    vector<vector<int>> groups(k);

    // Đọc input
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        flagArr[i] = x - 1;
        if (y == 0) {
            root = i;
        } else {
            int p = y - 1;
            adjList[i].push_back(p);
            adjList[p].push_back(i);
        }
        groups[flagArr[i]].push_back(i);
    }
    if (root == -1) return 0;

    // Xây LCA
    depth[root] = 0;
    dfs(root, -1);

    // Xử lý từng nhóm
    for (int g = 0; g < k; g++) {
        auto &vec = groups[g];
        if (vec.empty()) {
            cout << 0 << '\n';
            continue;
        }
        // Bước 1: tìm đỉnh xa nhất từ vec[0]
        int u = vec[0], far = u, maxd = -1;
        for (int v : vec) {
            int d = distanceNodes(u, v);
            if (d > maxd) {
                maxd = d;
                far = v;
            }
        }
        // Bước 2: tìm đỉnh xa nhất từ far
        maxd = 0;
        for (int v : vec) {
            maxd = max(maxd, distanceNodes(far, v));
        }
        cout << maxd << '\n';
    }

    return 0;
}