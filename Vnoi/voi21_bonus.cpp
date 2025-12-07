#include<bits/stdc++.h>
using namespace std;

#define int long long // Dùng int main() ở dưới để tránh lỗi
#define MAXN 1000005 // SỬA LỖI 1: Kích thước đủ cho 10^6 ký tự
#define MAX_VAL 100005
#define B_THRESHOLD 550

// Các mảng mới cho TLE
vector<int> heavy_adj[MAX_VAL]; // Chỉ lưu các "hàng xóm" Nặng
bool is_heavy[MAX_VAL];         // Đánh dấu p có phải là "Nặng"
long long max_dp_from_light_partner[MAX_VAL]; // Max dp từ hàng xóm "Nhẹ"

int child[MAXN][26];     // Chỉ lưu chỉ số node
int trie_max_dp[MAXN];   // Lưu giá trị dp lớn nhất của xâu KẾT THÚC tại node này
int lucky_max_dp[MAX_VAL]; // Lưu dp lớn nhất của số may mắn P
vector<int> adj[MAX_VAL];

int cnt = 0;
int n, m;

// Hàm 1: Thêm xâu vào Trie sau khi đã tính xong dp[i]
void insert_trie(string s, int val_dp) {
    int u = 0;
    for (char c : s) {
        int k = c - 'A';
        if (child[u][k] == 0) child[u][k] = ++cnt;
        u = child[u][k];
    }
    // Tại node kết thúc xâu s, cập nhật giá trị dp
    trie_max_dp[u] = max(trie_max_dp[u], val_dp);
}

// Hàm 2: Tìm max dp của các thẻ j > i mà S_j là tiền tố của s
int query_trie(string s) {
    int u = 0;
    int current_max = 0;
    
    // Duyệt theo xâu s
    for (int i = 0; i  < s.size()-1; i++) {
        int k = s[i] - 'A';
        if (child[u][k] == 0) break; // Không còn đường đi khớp
        u = child[u][k];
        
        // Nếu tại node u có xâu kết thúc (tức là tiền tố), lấy max
        current_max = max(current_max, trie_max_dp[u]);
    }
    return current_max;
}

void solve() {
    cin >> n >> m;
    
    vector<string> nhan(n);
    vector<int> val(n); // p_i <= 100,000, 'int' là đủ
    for (int i = 0; i < n; i++) cin >> nhan[i] >> val[i];
    
    // --- BƯỚC TIỀN XỬ LÝ (ĐỂ SỬA TLE) ---
    
    // 1. Đọc và xây dựng đồ thị đầy đủ
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 2. Đánh dấu các đỉnh "Nặng" (Heavy)
    for (int p = 0; p < MAX_VAL; p++) {
        if (adj[p].size() > B_THRESHOLD) {
            is_heavy[p] = true;
        }
    }

    // 3. Xây dựng danh sách kề CHỈ chứa các đỉnh "Nặng"
    for (int p = 0; p < MAX_VAL; p++) {
        for (int neighbor : adj[p]) {
            if (is_heavy[neighbor]) {
                heavy_adj[p].push_back(neighbor);
            }
        }
    }
    // --- KẾT THÚC TIỀN XỬ LÝ ---

    long long ans = 0; // Phải là long long
    
    // DUYỆT NGƯỢC TỪ N-1 VỀ 0
    for (int i = n-1; i >= 0; i--) {
        int p_i = val[i]; // Lấy giá trị p_i
        
        // 1. Tìm Bonus từ Prefix (Giữ nguyên) - Giả sử đã sửa query_trie
        long long prefix_bonus = query_trie(nhan[i]);
        
        // 2. Tìm Bonus từ Lucky Pair (ĐÃ TỐI ƯU TLE)
        // O(1): Lấy max từ tất cả partner "Nhẹ"
        long long lucky_bonus = max_dp_from_light_partner[p_i]; 
        
        // O(sqrt(M)): Chỉ duyệt qua các partner "Nặng"
        for (int heavy_neighbor : heavy_adj[p_i]) {
            lucky_bonus = max(lucky_bonus, lucky_max_dp[heavy_neighbor]);
        }
        
        // 3. Tính DP[i]
        long long current_dp = (long long)p_i + max({0LL, prefix_bonus, lucky_bonus});
        
        ans = max(ans, current_dp);
        
        // 4. Cập nhật thông tin thẻ i vào cấu trúc dữ liệu
        insert_trie(nhan[i], current_dp);
        
        // Tối ưu: Nếu giá trị mới không tốt hơn thì không cần update
        if (current_dp <= lucky_max_dp[p_i]) {
            continue;
        }
        
        lucky_max_dp[p_i] = current_dp; // Cập nhật max_dp cho chính nó

        // 4b. CẬP NHẬT TỐI ƯU (PUSH/PULL)
        if (is_heavy[p_i]) {
            // Nếu p_i là "Nặng", không làm gì cả (dùng logic "Pull" ở bước Query)
        } else {
            // Nếu p_i là "Nhẹ", "Đẩy" (Push) giá trị mới cho TẤT CẢ hàng xóm
            // O(B_THRESHOLD)
            for (int neighbor : adj[p_i]) {
                max_dp_from_light_partner[neighbor] = max(max_dp_from_light_partner[neighbor], current_dp);
            }
        }
    }
    
    cout << ans << endl;
}

#undef int
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}