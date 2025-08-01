#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define psb push_back
#define ppb pop_back
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";
int r, k, n;
vector<vector<int>> build_hex_adj(int R) {
    // Số hàng = 2*R - 1
    int H = 2*R - 1;
    // Tính độ dài mỗi hàng: len[r] = R + min(r, 2*R-2-r)
    vector<int> len(H);
    for (int r = 0; r < H; ++r)
        len[r] = R + min(r, 2*R-2-r);

    // 1) Khởi tạo các hàng chứa ID (1-based)
    vector<vector<int>> rows(H);
    int id = 1;
    for (int r = 0; r < H; ++r) {
        rows[r].resize(len[r]);
        for (int c = 0; c < len[r]; ++c)
            rows[r][c] = id++;
    }

    // 2) Tạo adjList size = N+1 (bỏ phần tử 0)
    int N = id - 1;
    vector<vector<int>> adj(N+1);

    // 3) Duyệt từng ô (r, c)
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < len[r]; ++c) {
            int u = rows[r][c];

            // 3.1) trái / phải
            if (c > 0)     adj[u].push_back(rows[r][c-1]);
            if (c+1 < len[r]) adj[u].push_back(rows[r][c+1]);

            // 3.2) hàng trên (r-1)
            if (r > 0) {
                int L = len[r-1];
                if (L < len[r]) {
                    // hàng trên ngắn hơn
                    if (c-1 >= 0   && c-1 < L) adj[u].push_back(rows[r-1][c-1]);
                    if (c   >= 0   && c   < L) adj[u].push_back(rows[r-1][c]);
                } else {
                    // hàng trên dài hơn hoặc bằng
                    if (c   >= 0   && c   < L) adj[u].push_back(rows[r-1][c]);
                    if (c+1 >= 0   && c+1 < L) adj[u].push_back(rows[r-1][c+1]);
                }
            }

            // 3.3) hàng dưới (r+1)
            if (r+1 < H) {
                int L = len[r+1];
                if (L < len[r]) {
                    // hàng dưới ngắn hơn
                    if (c-1 >= 0   && c-1 < L) adj[u].push_back(rows[r+1][c-1]);
                    if (c   >= 0   && c   < L) adj[u].push_back(rows[r+1][c]);
                } else {
                    // hàng dưới dài hơn hoặc bằng
                    if (c   >= 0   && c   < L) adj[u].push_back(rows[r+1][c]);
                    if (c+1 >= 0   && c+1 < L) adj[u].push_back(rows[r+1][c+1]);
                }
            }
        }
    }

    // 4) Loại trùng, sắp xếp (tùy chọn)
    for (int u = 1; u <= N; ++u) {
        sort(adj[u].begin(), adj[u].end());
        adj[u].erase(unique(adj[u].begin(), adj[u].end()), adj[u].end());
    }

    return adj;
}

void solve() {
    cin >> r >> k;
    n = pow(r,3) - pow(r-1,3);
    vector<vector<int>> adjList = build_hex_adj(r);
    vector<pair<bool,int>> store(MAXN,{false,0});
    for (int i = 0; i < k; i++) {
        int u; cin >> u;
        store[u].fi = true;
        for (int v : adjList[u]) store[v].se++;
    }
    int kq = 0;
    for (int i = 1; i <= n; i++) {
        if (store[i].fi) continue;
        kq += store[i].se % 6;
    }
    cout << kq;
}
    
int main() {
#ifndef ONLINE_JUDGE
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}