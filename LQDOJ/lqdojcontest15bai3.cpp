#include<bits/stdc++.h>
using namespace std;
#define int long long

// Định nghĩa vô cực
const int INF_MIN = -1e18;
const int INF_MAX = 1e18;

void solve() {
    int n, m; 
    if (!(cin >> n >> m)) return;

    vector<int> a(n + 1), c(n + 1);
    int sum_a = 0, sum_c = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum_a += a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        sum_c += c[i];
    }

    // Tăng kích thước mảng k lên sum_a + 1 để tránh lỗi mảng (Out of bounds)
    // Nếu đề bài cam kết sum_a <= 500 thì để 505 cũng được, nhưng dùng sum_a an toàn hơn
    int max_k = sum_a; 
    
    // dp[i][j][k] = {max_c, min_c}
    // i: Đã xét i vật đầu tiên
    // j: Đã chọn đúng j vật
    // k: Tổng trọng số a là k
    vector<vector<vector<pair<int,int>>>> dp(n + 1, 
        vector<vector<pair<int,int>>>(m + 1, 
        vector<pair<int,int>>(max_k + 1, {INF_MIN, INF_MAX})));

    // Khởi tạo: Xét 0 vật, chọn 0 vật, tổng a=0 -> tổng c=0
    dp[0][0][0] = {0, 0};

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= max_k; k++) {
                
                // 1. Trường hợp KHÔNG CHỌN vật thứ i
                // Thừa kế hoàn toàn từ trạng thái i-1
                dp[i][j][k] = dp[i-1][j][k];

                // 2. Trường hợp CÓ CHỌN vật thứ i
                // Điều kiện: Phải chọn ít nhất 1 vật (j >= 1) và tổng a đủ lớn (k >= a[i])
                if (j >= 1 && k >= a[i]) {
                    // Trạng thái trước đó phải hợp lệ (không phải vô cực)
                    if (dp[i-1][j-1][k-a[i]].first != INF_MIN) {
                        
                        int prev_max = dp[i-1][j-1][k-a[i]].first;
                        int prev_min = dp[i-1][j-1][k-a[i]].second;

                        // Cập nhật Max
                        dp[i][j][k].first = max(dp[i][j][k].first, prev_max + c[i]);
                        // Cập nhật Min
                        dp[i][j][k].second = min(dp[i][j][k].second, prev_min + c[i]);
                    }
                }
            }
        }
    }

    double kq = 1e18;
    for (int k = 1; k < sum_a; k++) {
        if (dp[n][m][k].first == INF_MIN) continue;

        double x1_max = dp[n][m][k].first;
        double x1_min = dp[n][m][k].second;
        
        double val1 = (x1_max / k) * ((double)(sum_c - x1_max) / (sum_a - k));
        
        double val2 = (x1_min / k) * ((double)(sum_c - x1_min) / (sum_a - k));

        kq = min({kq, val1, val2});
    }

    if (kq == 1e18) cout << -1;
    else cout << fixed << setprecision(3) << kq;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}