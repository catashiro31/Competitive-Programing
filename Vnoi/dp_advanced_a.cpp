#include <iostream>
#include <vector>
#include <algorithm> // Dùng cho max() và sort()
#include <functional> // Dùng cho greater<long long>()
#include <cstring>    // Dùng cho memset()

using namespace std;

// Số đỉnh tối đa
const int MAXN = 5005;

// dp[u][0] = số cặp tối đa trong cây con u, nếu u tô TRẮNG
// dp[u][1] = số cặp tối đa trong cây con u, nếu u tô ĐEN
long long dp[MAXN][2];

// Danh sách kề biểu diễn cây
vector<int> adj[MAXN];

/**
 * Hàm đệ quy DFS để tính toán Quy hoạch động
 * u: Nút hiện tại
 * p: Nút cha của u (để tránh duyệt ngược)
 */
void dfs(int u, int p) {
    // 1. Khởi tạo giá trị DP cho nút u
    // Nếu u là lá, cả hai giá trị đều là 0
    dp[u][0] = 0;
    dp[u][1] = 0;

    // 2. Chuẩn bị cho việc tính dp[u][1] (u tô Đen)
    
    // `base_score_for_black` là tổng điểm nếu tất cả con đều tô Đen
    long long base_score_for_black = 0;
    
    // `gains` lưu lợi ích của việc chuyển một con `v`
    // từ Đen sang Trắng (lợi ích = dp[v][0] - dp[v][1])
    vector<long long> gains;

    // 3. Duyệt qua tất cả các con v của u (Duyệt Post-order)
    for (int v : adj[u]) {
        if (v == p) continue; // Không duyệt ngược lên cha

        // Gọi đệ quy để tính toán cho con v trước
        dfs(v, p);

        // 4. Tính dp[u][0] (u tô Trắng)
        // Nếu u là Trắng, nó "reset" lại.
        // Ta chỉ cần lấy giá trị tốt nhất từ mỗi cây con v.
        dp[u][0] += max(dp[v][0], dp[v][1]);

        // 5. Thu thập dữ liệu để tính dp[u][1] (u tô Đen)
        // Cộng điểm cơ sở (giả sử v tô Đen)
        base_score_for_black += dp[v][1];
        // Tính lợi ích nếu chuyển v sang Trắng
        gains.push_back(dp[v][0] - dp[v][1]);
    }

    // 6. Tính dp[u][1] (u tô Đen)
    // Sắp xếp các lợi ích theo thứ tự giảm dần
    sort(gains.begin(), gains.end(), greater<long long>());

    // Bắt đầu với trường hợp k=0 (0 con tô Trắng)
    // Điểm = điểm cơ sở + 0 cặp mới
    dp[u][1] = base_score_for_black;

    long long current_gain_sum = 0;
    // Duyệt qua các khả năng: 1 con Trắng, 2 con Trắng, ...
    for (int k = 0; k < gains.size(); k++) {
        // Lấy k lợi ích tốt nhất
        current_gain_sum += gains[k];
        
        // Số lượng con tô Trắng
        long long num_white_children = k + 1;
        
        // Số cặp mới được tạo ra tại u
        long long new_pairs = (num_white_children * (num_white_children - 1)) / 2;

        // Tổng điểm = điểm cơ sở + tổng lợi ích + số cặp mới
        long long total_score = base_score_for_black + current_gain_sum + new_pairs;

        // Cập nhật giá trị tốt nhất cho dp[u][1]
        dp[u][1] = max(dp[u][1], total_score);
    }
}

/**
 * Hàm xử lý mỗi test case
 */
void solve() {
    int n;
    cin >> n;

    // Xóa dữ liệu của test case trước
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    // Không cần memset dp vì dfs sẽ ghi đè giá trị

    // Đọc n-1 cạnh của cây
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Bắt đầu DFS từ gốc (chọn nút 1) với cha ảo là 0
    dfs(1, 0);

    // Kết quả cuối cùng là giá trị tốt nhất ở gốc,
    // bất kể gốc tô Trắng hay Đen.
    cout << max(dp[1][0], dp[1][1]) << "\n";
}

int main() {
    // Tăng tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}