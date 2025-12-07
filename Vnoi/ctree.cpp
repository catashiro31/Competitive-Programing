#include <iostream>
#include <vector>
#include <algorithm> // Dùng cho min()
#include <cstdio>    // Dùng cho printf/scanf nếu bạn thích

using namespace std;

// Số đỉnh tối đa
const int MAXN = 10005;

// Danh sách kề biểu diễn cây
vector<int> adj[MAXN];

// mảng `group[i]` sẽ lưu 1 hoặc 2,
// cho biết đỉnh `i` thuộc nhóm 1 hay nhóm 2
int group[MAXN];

// mảng `label[i]` sẽ lưu nhãn cuối cùng (1 hoặc 2)
int label[MAXN];

// đếm số lượng đỉnh trong mỗi nhóm
long long cnt[3]; // cnt[1] và cnt[2]

int n;

/**
 * Hàm DFS để "tô màu" cây thành 2 nhóm (1 và 2)
 * u: Nút hiện tại
 * p: Nút cha (để tránh đi ngược)
 * current_group: Nhóm của nút u (1 hoặc 2)
 */
void dfs(int u, int p, int current_group) {
    // Gán nút u vào nhóm hiện tại
    group[u] = current_group;
    // Tăng số đếm của nhóm đó
    cnt[current_group]++;

    // Duyệt qua các con của u
    for (int v : adj[u]) {
        if (v != p) {
            // "Tô màu" cho con `v` bằng nhóm còn lại (3 - 1 = 2, 3 - 2 = 1)
            dfs(v, u, 3 - current_group);
        }
    }
}

int main() {
    // Tăng tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    // Đọc n-1 cạnh
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Khởi tạo số đếm
    cnt[1] = 0;
    cnt[2] = 0;

    // Bắt đầu DFS từ gốc 1, gán nó vào nhóm 1
    dfs(1, 0, 1);

    // Tính 2 kịch bản chi phí
    // Kịch bản 1: Nhóm 1 gán nhãn 1, Nhóm 2 gán nhãn 2
    long long s1 = (cnt[1] * 1) + (cnt[2] * 2);

    // Kịch bản 2: Nhóm 1 gán nhãn 2, Nhóm 2 gán nhãn 1
    long long s2 = (cnt[1] * 2) + (cnt[2] * 1);

    // Chọn kịch bản có tổng chi phí (S) nhỏ hơn
    long long S;
    int final_label_group1, final_label_group2;

    if (s1 <= s2) {
        S = s1;
        final_label_group1 = 1;
        final_label_group2 = 2;
    } else {
        S = s2;
        final_label_group1 = 2;
        final_label_group2 = 1;
    }

    // In tổng S
    cout << S << "\n";

    // Gán nhãn cuối cùng cho các đỉnh và in ra
    for (int i = 1; i <= n; ++i) {
        if (group[i] == 1) {
            label[i] = final_label_group1;
        } else {
            label[i] = final_label_group2;
        }
        cout << label[i] << "\n";
    }

    return 0;
}