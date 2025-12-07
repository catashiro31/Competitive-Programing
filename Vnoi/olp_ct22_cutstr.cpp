#include<bits/stdc++.h>
using namespace std;

#define int long long
#define psb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define MAXN 100005 

string s;
int n;
vector<int> hashT(MAXN), rhashT(MAXN), base(MAXN);

int ghash(int u, int v) {
    return (hashT[v] - (hashT[u-1]*base[v-u+1])%MOD + MOD) % MOD;
}

int grhash(int u, int v) {
    return (rhashT[n-u+1] - (rhashT[n-v]*base[v-u+1])%MOD + MOD) % MOD;
}

bool isPalindrome(int u, int v) {
    if (u > v) return true;
    return ghash(u, v) == grhash(u, v);
}

void solve() {
    cin >> s;
    n = sz(s);
    
    hashT[0] = 0; rhashT[0] = 0; base[0] = 1;
    for (int i = 1; i <= n; i++) {
        hashT[i] = (hashT[i-1]*331 + (s[i-1]-'a'+1)) % MOD;
        rhashT[i] = (rhashT[i-1]*331 + (s[n-i]-'a'+1)) % MOD;
        base[i] = (base[i-1]*331) % MOD;
    }

    int t_case;
    if (!(cin >> t_case)) return;
    
    while (t_case--) {
        int k; 
        cin >> k;
        vector<int> l(k);
        vector<int> unique_lens;
        for (int i = 0; i < k; i++) {
            cin >> l[i];
            unique_lens.psb(l[i]);
        }
        
        sort(all(unique_lens));
        unique_lens.erase(unique(all(unique_lens)), unique_lens.end());

        vector<vector<int>> pos_map(n + 1); 
        
        for (int len : unique_lens) {
            if (len > n) continue;
            for (int i = 1; i <= n - len + 1; i++) {
                if (isPalindrome(i, i + len - 1)) {
                    pos_map[len].psb(i);
                }
            }
        }

        // 3. Bitmask DP
        // dp[mask] = chỉ số KẾT THÚC nhỏ nhất của chuỗi con tạo bởi tập mask
        int num_states = 1 << k;
        vector<int> dp(num_states, n + 2); // Khởi tạo giá trị vô cùng (n+2)
        dp[0] = 0; // Trạng thái rỗng kết thúc tại 0

        for (int mask = 0; mask < num_states; mask++) {
            // Nếu trạng thái này không thể đạt được, bỏ qua
            if (dp[mask] > n) continue;

            int current_end = dp[mask];

            // Thử thêm palindrome thứ i vào tập hợp
            for (int i = 0; i < k; i++) {
                if (!((mask >> i) & 1)) { // Nếu bit i chưa bật
                    int len = l[i];
                    int next_mask = mask | (1 << i);

                    // Tìm vị trí bắt đầu hợp lệ sớm nhất > current_end
                    // Ta cần palindrome bắt đầu tại 'start' sao cho start > current_end
                    // Tức là start >= current_end + 1
                    
                    // Nếu độ dài len không tồn tại trong chuỗi thì bỏ qua luôn
                    if (pos_map[len].empty()) continue;

                    // Tìm kiếm nhị phân (upper_bound) để tìm vị trí start
                    // pos_map[len] chứa các vị trí start đã sort tăng dần
                    auto it = lower_bound(all(pos_map[len]), current_end + 1);

                    if (it != pos_map[len].end()) {
                        int start = *it;
                        int new_end = start + len - 1;
                        
                        // Cập nhật DP: lấy min của các cách đến được next_mask
                        if (new_end < dp[next_mask]) {
                            dp[next_mask] = new_end;
                        }
                    }
                }
            }
        }

        if (dp[num_states - 1] <= n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}