#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adjList;     // Danh sách kề của đồ thị
vector<vector<int>> TadjList;    // Danh sách kề của đồ thị chuyển vị
vector<bool> visited;
stack<int> st;

void DFS1(int u) {
    visited[u] = true;
    for (int v : adjList[u]) {
        if (!visited[v]) {
            DFS1(v);
        }
    }
    st.push(u);  // Đẩy đỉnh vào stack sau khi đã hoàn thành DFS trên nó
}

void DFS2(int u) {
    cout << u << " ";   // Xuất đỉnh thuộc thành phần liên thông mạnh
    visited[u] = true;
    for (int v : TadjList[u]) {
        if (!visited[v]) {   // Sửa lỗi: kiểm tra visited[v], không phải visited[u]
            DFS2(v);
        }
    }
}

void kosaraju() {
    // Bước 1: Duyệt DFS trên đồ thị ban đầu để đẩy các đỉnh vào stack theo thứ tự kết thúc DFS
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            DFS1(i);
        }
    }
    
    // Bước 2: Duyệt DFS trên đồ thị chuyển vị
    int scc = 0;  // Biến đếm số thành phần liên thông mạnh
    fill(visited.begin(), visited.end(), false);  // Reset visited
    
    while (!st.empty()) {
        int top = st.top(); st.pop();
        if (!visited[top]) {
            ++scc;  // Đếm số thành phần liên thông mạnh
            DFS2(top);  // Tìm SCC từ đỉnh này
            cout << '\n';
        }
    }
    cout << "SCC: " << scc << '\n';
}

void input() {
    ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
    inFile >> n >> m;
    
    adjList.assign(n + 1, vector<int>());
    TadjList.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int u, v; inFile >> u >> v;
        adjList[u].push_back(v);      // Đồ thị ban đầu
        TadjList[v].push_back(u);     // Đồ thị chuyển vị
    }
    inFile.close();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    kosaraju();
}

