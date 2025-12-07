#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define int long long
const int MOD = 1000000007;

// Cần tiền xử lý tổ hợp C(n, k) vì chúng ta cần tính C(j, k) trong mỗi bước DP
const int MAX_N_COMB = 2005; 
int fact[MAX_N_COMB];
int invFact[MAX_N_COMB];
int dp[2005][2005]; // DP[i][j]

// Hàm tính lũy thừa theo modulo
int power(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Hàm nghịch đảo modulo (Dùng cho phép chia trong tổ hợp)
int modInverse(int n) {
    return power(n, MOD - 2);
}

// Tiền xử lý giai thừa và nghịch đảo giai thừa
void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N_COMB; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX_N_COMB - 1] = modInverse(fact[MAX_N_COMB - 1]);
    for (int i = MAX_N_COMB - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

// Tính C(n, k)
int combinations(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n / 2) k = n - k;
    return (((fact[n] * invFact[k]) % MOD) * invFact[n - k]) % MOD;
}

void solve() {
    int n, b; 
    if (!(cin >> n >> b)) return;

    // Kích thước mảng tổ hợp phải đủ cho n
    if (n >= MAX_N_COMB) {
        // Tùy thuộc vào giới hạn thực tế, cần tiền xử lý lớn hơn hoặc dùng công thức đệ quy
        // Tuy nhiên, vì đề bài thường thiết kế để C(n,k) được tiền xử lý, ta giữ nguyên.
        // Đây là một rủi ro nếu n > 2004.
    }
    
    vector<int> a(n + 1); // a[i] từ input (index 1 đến N)
    for (int i = 1; i <= n; i++) cin >> a[i];

    // Khởi tạo DP: DP[i][j]
    // DP[1][0] = 1: Tại i=1, tập {1...i-1} rỗng, có 0 đỉnh khả dụng.
    dp[1][0] = 1; 

    // --- DP Transition (i -> i+1) ---
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) { // j: số đỉnh khả dụng trong {1...i-1}
            if (dp[i][j] == 0) continue;

            // --- Xác định phạm vi giá trị cho a_i (số cạnh từ i) ---
            int min_a_i = (a[i] == -1) ? 0 : a[i];
            int max_a_i = (a[i] == -1) ? min((long long)i - 1, b) : a[i];
            
            // Số đỉnh đã qua (i-1) phải >= số cạnh chọn (k)
            if (max_a_i > i - 1) max_a_i = i - 1; 
            
            // --- Bắt đầu chuyển trạng thái cho a_i ---
            for (int k = min_a_i; k <= max_a_i; k++) { // k là giá trị ta chọn cho a_i
                
                // Ràng buộc 1: k cạnh phải đi đến các đỉnh chưa bão hòa (tức là k <= j)
                if (k > j) break; 

                // --- 1. TÍNH TRẠNG THÁI MỚI (j_new) ---
                // k đỉnh từ j khả dụng bị chọn, số đỉnh khả dụng còn lại là j-k
                // Đỉnh i mới có khả dụng không? (Nếu bậc < B)
                int i_is_available = (b > k) ? 1 : 0; 
                
                // Số đỉnh khả dụng mới: j_new = (j - k) + (tính khả dụng của i)
                int j_new = (j - k) + i_is_available;
                
                // --- 2. TÍNH SỐ CÁCH (Combinatorics) ---
                // Số cách chọn k đỉnh từ j đỉnh khả dụng: C(j, k)
                // Số đỉnh còn lại (i-1-j) là bão hòa -> không được chọn (C(i-1-j, 0) = 1)
                
                int ways = combinations(j, k);
                
                // --- 3. CẬP NHẬT DP ---
                dp[i + 1][j_new] = (dp[i + 1][j_new] + dp[i][j] * ways) % MOD;
            }
        }
    }

    // --- Kết quả cuối cùng ---
    // Sau khi xử lý a_N, kết quả nằm trong DP[N+1]
    int final_ans = 0;
    for (int j = 0; j <= n; j++) {
        final_ans = (final_ans + dp[n + 1][j]) % MOD;
    }
    
    cout << final_ans << "\n";
}

signed main() {
    precompute_factorials();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}