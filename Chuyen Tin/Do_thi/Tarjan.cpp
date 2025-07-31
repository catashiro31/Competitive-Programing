#include <bits/stdc++.h>
using namespace std;
const int UNVISITED = -1;
vector<vector<int>> adj;  // Danh sách kề của đồ thị
vector<int> disc, low;    // Mảng lưu thời gian khám phá và giá trị low-link
vector<bool> in_stack;    // Mảng đánh dấu đỉnh nào đang ở trong stack
stack<int> st;            // Stack để lưu các đỉnh đang được duyệt
int timeDfs;              // Biến thời gian để cập nhật chỉ số duyệt DFS

// Hàm DFS tìm SCC bắt đầu từ đỉnh u
void DFS(int u) {
    disc[u] = low[u] = ++timeDfs;  // Gán giá trị discovery time và low-link value
    st.push(u);                    // Đưa đỉnh u vào stack
    in_stack[u] = true;            // Đánh dấu đỉnh u trong stack

    // Duyệt qua các đỉnh kề của u
    for (int v : adj[u]) {
        if (disc[v] == UNVISITED) {
            // Nếu đỉnh v chưa được duyệt thì thực hiện DFS(v)
            DFS(v);
            low[u] = min(low[u], low[v]);  // Cập nhật low-link value của u
        } else if (in_stack[v]) {
            // Nếu v đang ở trong stack, cập nhật low-link value của u
            low[u] = min(low[u], disc[v]);
        }
    }

    // Nếu u là gốc của một SCC, xuất SCC đó
    if (disc[u] == low[u]) {
        while (true) {
            int v = st.top();
            st.pop();
            in_stack[v] = false;
            cout << v << " ";
            if (v == u) break;
        }
        cout << '\n';
    }
}

// Hàm khởi tạo và tìm các SCC
void findSCCs(int n) {
    // Khởi tạo các mảng
    disc.assign(n, UNVISITED);   // Khởi tạo tất cả các đỉnh đều chưa được thăm
    low.assign(n, 0);
    in_stack.assign(n, false);
    timeDfs = 0;                 // Biến đếm thời gian duyệt DFS

    // Duyệt qua từng đỉnh để tìm SCC
    for (int i = 0; i < n; i++) {
        if (disc[i] == UNVISITED) {
            DFS(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
    int n, m;
    inFile >> n >> m;

    adj.assign(n, vector<int>());  // Khởi tạo danh sách kề
    for (int i = 0; i < m; i++) {
        int u, v;
        inFile >> u >> v;
        adj[u].push_back(v);  // Thêm cạnh có hướng từ u tới v
    }
    inFile.close();
    findSCCs(n);

    return 0;
}
