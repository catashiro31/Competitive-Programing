#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005
int n, k;
int kq = 0;
vector<vector<int>> dp;

int backtracking(int u, int dst, int val) {
    if (val == 0) return 0;
    if (u == dst) {
        return val % MOD;
    }
    if (dp[u][val] != -1) {
        return dp[u][val];
    }
    int current_sum = 0;
    // 1. Khai báo r trong vòng for
    // 2. Bước nhảy là l = r + 1 thay vì l++
    for (int l = 1, r; l <= val; l = r + 1) {
        // TÍNH r: Giới hạn trên của khoảng [l, r] có cùng thương
        r = val / (val / l);
        int next_val = val / l;
        int ways = backtracking(u + 1, dst, next_val);
        // Số lượng phần tử trong đoạn [l, r]
        int count = (r - l + 1); 
        // Cộng dồn kết quả: (số lượng * kết quả của nhánh con)
        // Lưu ý ép kiểu long long để tránh tràn số trước khi MOD
        current_sum = (current_sum + count * ways) % MOD;
    }
    return dp[u][val] = current_sum;
}

void solve() {
	cin >> n >> k;
	dp.assign(k, vector<int>(n + 1, -1));
	cout << backtracking(0, k - 1, n) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
