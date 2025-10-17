#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) (int)x.size()

// ===== Fenwick: range add [l,r], point query p =====
struct BIT {
    int n; vector<long long> f;
    BIT(int n=0){ init(n); }
    void init(int n_){ n = n_; f.assign(n+2, 0); }
    void add(int i, long long v){ for (; i<=n; i+=i&-i) f[i]+=v; }
    void range_add(int l, int r, long long v){
        if (l>r) return;
        add(l, v);
        add(r+1, -v);
    }
    long long sum(int i){ long long s=0; for (; i>0; i-=i&-i) s+=f[i]; return s; }
};

vector<int> degree(100000+5, 1);
vector<pair<int,int>> path_(100000+5);
int timerK = 1;

void DFS(int u, int par, const vector<vector<int>> &adj) {
    path_[u].first = timerK++;
    for (int v : adj[u]) {
        if (v == par) continue;
        degree[v] = degree[u] + 1;
        DFS(v, u, adj);
    }
    path_[u].second = timerK - 1;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; ++i) {
        int u,v; cin >> u >> v; --u; --v;
        adj[u].psb(v); adj[v].psb(u);
    }

    // reset timer (phòng nhiều test)
    timerK = 1;
    DFS(0, -1, adj);

    vector<pair<int,int>> arr(n);
    for (int i = 0; i < n; ++i) arr[i] = {degree[i], path_[i].first};
    sort(all(arr));

    BIT bit(n); // BIT chạy trên chỉ số 1..n (ứng với vị trí trong mảng arr đã sort)

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int u, k, e; cin >> u >> k >> e; --u;
            int deg = degree[u] + k;
            int L_in = path_[u].first, R_in = path_[u].second;

            // tìm đoạn trong arr có (depth == deg) và in[u] nằm trong [L_in, R_in]
            pair<int,int> dst = {deg, L_in};
            pair<int,int> den = {deg, R_in};
            int lb = int(lower_bound(all(arr), dst) - arr.begin());
            int ub = int(upper_bound(all(arr), den) - arr.begin()) - 1;

            if (lb <= ub) {
                // arr là 0-based, BIT là 1-based
                bit.range_add(lb+1, ub+1, e);
            }
        } else {
            int u; cin >> u; --u;
            pair<int,int> key = {degree[u], path_[u].first};
            int pos0 = int(lower_bound(all(arr), key) - arr.begin()); // 0-based
            long long ans = bit.sum(pos0+1); // 1-based cho BIT
            cout << ans << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}
