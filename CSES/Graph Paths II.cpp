#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;

// Hàm nhân hai ma trận với mục tiêu tìm tổng nhỏ nhất
vector<vector<ll>> Multi(vector<vector<ll>> a, vector<vector<ll>> b) {
    int n = a.size();
    vector<vector<ll>> kq(n, vector<ll>(n, LLONG_MAX));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (a[i][k] != LLONG_MAX && b[k][j] != LLONG_MAX) {
                    kq[i][j] = min(kq[i][j], a[i][k] + b[k][j]);
                }
            }
        }
    }
    return kq;
}

// Hàm lũy thừa nhanh ma trận
vector<vector<ll>> Pow(vector<vector<ll>> base, ll exp) {
    int n = base.size();
    vector<vector<ll>> ans(n, vector<ll>(n, LLONG_MAX));

    // Khởi tạo ma trận đơn vị
    for (int i = 0; i < n; ++i) ans[i][i] = 0;

    // Lũy thừa nhanh
    while (exp) {
        if (exp & 1) ans = Multi(ans, base);
        base = Multi(base, base);
        exp >>= 1;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    ll k;
    cin >> k;

    // Khởi tạo ma trận trọng số
    vector<vector<ll>> grid(n, vector<ll>(n, LLONG_MAX));
    for (int i = 0; i < m; i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        --u, --v;
        grid[u][v] = min(grid[u][v],c); // Đọc cạnh và trọng số
    }

    // Lũy thừa ma trận
    grid = Pow(grid, k);

    // Kiểm tra kết quả
    if (grid[0][n - 1] != LLONG_MAX)
        cout << grid[0][n - 1];
    else
        cout << -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}