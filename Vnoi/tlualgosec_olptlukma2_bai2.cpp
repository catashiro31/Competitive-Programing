#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long L;
vector<long long> w;
vector<long long> P; // Mảng cộng dồn độ dài từ

// Hàm kiểm tra xem có thể phân trang với hệ số phạt tối đa là 'limit' hay không
bool check(long long limit) {
    long long min_req = L - limit; // Tổng độ dài tối thiểu mỗi dòng phải đạt
    
    // dp[i] = true nghĩa là có thể phân trang hợp lệ cho i từ đầu tiên
    vector<bool> dp(N + 1, false);
    dp[0] = true;

    // cnt_true[i] lưu số lượng giá trị true trong mảng dp từ 0 đến i-1
    // Dùng để truy vấn nhanh xem trong đoạn [l, r] có thằng dp nào true không
    vector<int> cnt_true(N + 2, 0);
    cnt_true[1] = 1; // Tương ứng dp[0] là true

    int l = 0, r = 0; // Cửa sổ trượt cho chỉ số j

    for (int i = 1; i <= N; ++i) {
        // Ta cần tìm j < i sao cho:
        // 1. P[i] - P[j] <= L       => P[j] >= P[i] - L
        // 2. P[i] - P[j] >= min_req => P[j] <= P[i] - min_req
        
        long long lower_bound_val = P[i] - L;
        long long upper_bound_val = P[i] - min_req;

        // Nếu một từ quá dài vượt quá L, chắc chắn không xếp được
        if (w[i] > L) return false; 

        // Di chuyển l sang phải để thỏa mãn điều kiện 1 (P[j] >= P[i] - L)
        while (l < i && P[l] < lower_bound_val) {
            l++;
        }

        // Di chuyển r sang phải để thỏa mãn điều kiện 2 tối đa (P[j] <= P[i] - min_req)
        // r là chỉ số lớn nhất thỏa mãn
        while (r + 1 < i && P[r + 1] <= upper_bound_val) {
            r++;
        }
        
        // Kiểm tra lại r có thỏa mãn điều kiện không (do vòng while có thể chưa chạy nếu r đã lớn sẵn)
        // Cần đảm bảo P[r] <= upper_bound_val. Nếu ngay cả P[l] > upper_bound_val thì vô nghiệm.
        if (l <= r && P[r] <= upper_bound_val) {
            // Kiểm tra trong đoạn dp[l...r] có giá trị true nào không
            // Sử dụng mảng cộng dồn cnt_true: số lượng true trong [l, r] là cnt_true[r+1] - cnt_true[l]
            if (cnt_true[r + 1] - cnt_true[l] > 0) {
                dp[i] = true;
            }
        }

        // Cập nhật mảng cộng dồn cho dp
        cnt_true[i + 1] = cnt_true[i] + (dp[i] ? 1 : 0);
    }

    return dp[N];
}

int main() {
    // Tối ưu nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> L)) return 0;

    w.resize(N + 1);
    P.resize(N + 1, 0);

    long long max_word_len = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> w[i];
        P[i] = P[i - 1] + w[i];
        max_word_len = max(max_word_len, w[i]);
    }

    // Nếu có từ dài hơn L thì không thể xếp được (theo logic thông thường đề bài đảm bảo w[i] <= L)
    // Nhưng ta cứ xử lý để tìm kiếm nhị phân chính xác.
    if (max_word_len > L) {
        // Tùy đề bài, nhưng thường input đảm bảo w[i] <= L. 
        // Nếu không, output trường hợp lỗi hoặc L.
    }

    // Tìm kiếm nhị phân kết quả (Binary Search Answer)
    // Hệ số phạt nhỏ nhất có thể là 0, lớn nhất là L
    long long left = 0, right = L;
    long long ans = L;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(mid)) {
            ans = mid;      // Thỏa mãn, thử tìm kết quả nhỏ hơn
            right = mid - 1;
        } else {
            left = mid + 1; // Không thỏa mãn, cần nới lỏng (tăng) phạt lên
        }
    }

    cout << ans << endl;

    return 0;
}