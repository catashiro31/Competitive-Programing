#include <iostream>
#include <vector>

using namespace std;

// Hàm tính C(n, k) % p với n, k nhỏ (n < p)
// Vì p ở đây chỉ là 2 hoặc 5 nên ta có thể tính trực tiếp đơn giản
int C_small(int n, int k, int p) {
    if (k > n) return 0;
    long long res = 1;
    // Tính nCk = n! / (k! * (n-k)!)
    // Sử dụng công thức nhân dần để tránh tràn số và giữ phép chia nguyên
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1);
        res /= i;
    }
    return res % p;
}

// Định lý Lucas: Tính C(n, k) % p với p là số nguyên tố
int lucas(long long n, long long k, int p) {
    if (k == 0) return 1;
    // C(n, k) % p = C(n%p, k%p) * lucas(n/p, k/p) % p
    return (lucas(n / p, k / p, p) * C_small(n % p, k % p, p)) % p;
}

void solve() {
    long long n, k;
    if (!(cin >> n >> k)) return;

    // Tính số dư cho 2
    int rem2 = lucas(n, k, 2);

    // Tính số dư cho 5
    int rem5 = lucas(n, k, 5);

    // Tìm kết quả x (0 <= x < 10) sao cho:
    // x % 2 == rem2 VÀ x % 5 == rem5
    for (int x = 0; x < 10; ++x) {
        if (x % 2 == rem2 && x % 5 == rem5) {
            cout << x << "\n";
            return;
        }
    }
}

int main() {
    // Tối ưu I/O cho C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}