#include <bits/stdc++.h>
using namespace std;

int n, m;  // số đỉnh và số cạnh
vector<vector<int>> adj;  // danh sách kề cho đồ thị ban đầu
vector<vector<int>> directedGraph;  // danh sách kề cho đồ thị có hướng
vector<bool> visited;  // mảng đánh dấu các đỉnh đã thăm

// Hàm DFS để duyệt qua đồ thị và định hướng các cạnh
void DFSVisit(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            // Định hướng cạnh (u, v)
            directedGraph[u].push_back(v);
            // Thực hiện DFS tiếp tục với đỉnh v
            DFSVisit(v);
        }
        // Định hướng cạnh (u, v) thành (v, u) nếu chưa được thăm
        else if (find(directedGraph[v].begin(), directedGraph[v].end(), u) == directedGraph[v].end()) {
            directedGraph[u].push_back(v);
        }
    }
}

void createDirectedGraph() {
    // Đánh dấu tất cả các đỉnh là chưa thăm
    visited.assign(n + 1, false);
    
    // Bắt đầu duyệt DFS từ các đỉnh chưa được thăm
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            DFSVisit(i);
        }
    }
}

void input() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
    inFile >> n >> m;
    adj.assign(n + 1, vector<int>());
    directedGraph.assign(n + 1, vector<int>());
    
    // Đọc các cạnh của đồ thị
    for (int i = 0; i < m; ++i) {
        int u, v;
        inFile >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Đồ thị ban đầu là vô hướng
    }
    inFile.close();
}

void output() {
    cout << "Directed Graph (after orientation):\n";
    for (int u = 1; u <= n; ++u) {
        for (int v : directedGraph[u]) {
            cout << u << " -> " << v << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();  // Đọc đồ thị ban đầu
    createDirectedGraph();  // Định hướng các cạnh theo DFS
    output();  // Xuất đồ thị có hướng

    return 0;
}
