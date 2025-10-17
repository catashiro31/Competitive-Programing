#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

bool check(long long m, long long x, long long a, long long y, long long b, long long n) {
    if (m == 0) return true;

    if (a > b) {
        swap(a, b);
        swap(x, y);
    }

    // Số lượng máy mỗi loại cần thiết để tạo gói có giá trị >= m
    long long da = (m + a - 1) / a;
    long long db = (m + b - 1) / b;

    // Duyệt i: số phòng nhận gói chỉ có máy loại a (máy rẻ hơn)
    for (long long i = 0; i <= n; ++i) {
        // Lượng máy a cần cho i phòng
        long long needed_x = i * da;
        if (needed_x > x) {
            break; // Không đủ máy a, dừng lại
        }

        // Số phòng còn lại cần được cấp
        long long remaining_n = n - i;
        if (remaining_n <= 0) {
            return true; // Đã cấp đủ
        }

        // Số máy a còn lại
        long long remaining_x = x - needed_x;
        
        // Kiểm tra xem số máy còn lại có đủ cho remaining_n phòng không
        // Cách 1: Kiểm tra đơn giản bằng tổng giá trị (thường đủ mạnh)
        if (remaining_x * a + y * b >= remaining_n * m) {
            // Cách 2: Kiểm tra chặt chẽ hơn
            // Số phòng có thể cấp bằng gói toàn máy b
            long long count_b_only = y / db;
            if (count_b_only >= remaining_n) {
                return true;
            }
        }
    }
    
    // Thử một cách duyệt khác: duyệt số phòng nhận gói máy đắt
    for (long long i = 0; i <= n; ++i) {
        long long needed_y = i * db;
        if (needed_y > y) {
            break;
        }

        long long remaining_n = n - i;
        if (remaining_n <= 0) {
            return true;
        }
        
        long long remaining_y = y - needed_y;

        if (x * a + remaining_y * b >= remaining_n * m) {
             if (x / da >= remaining_n) return true;
        }
    }


    return false; // Không tìm được cách nào
}

void solve() {
    long long x, a, y, b, n;
    cin >> x >> a >> y >> b >> n;

    long long low = 0, high = 2e9, ans = 0; // Đặt high đủ lớn

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, x, a, y, b, n)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1; 
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 2;
    while (t--) {
        solve();
    }
    return 0;
}