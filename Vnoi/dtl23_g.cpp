#include <bits/stdc++.h>
using namespace std;

vector<int> euler_start, euler_end;
int timer = 1;

void euler(int u, int par, const vector<vector<int>> &adj) {
    euler_start[u] = timer++;
    for (int v : adj[u]) if (v != par) euler(v, u, adj);
    euler_end[u] = timer - 1;
}

unordered_map<int, vector<int>> divisor;
void process(const vector<int> &val, int n) {
    for (int i = 1; i <= n; ++i) {
        int x = val[i];
        for (int j = 1; 1LL*j*j <= x; ++j) {
            if (x % j == 0) {
                divisor[j].push_back(euler_start[i]);
                int k2 = x / j;
                if (k2 != j) divisor[k2].push_back(euler_start[i]);
            }
        }
    }
    
    for (auto &p : divisor) {
        auto &vec = p.second;
        sort(vec.begin(), vec.end());
    }
}

int range_count(int L, int R, int k) {
    auto &vec = divisor[k];
    int lb = lower_bound(vec.begin(), vec.end(), L) - vec.begin();
    int ub = upper_bound(vec.begin(), vec.end(), R) - vec.begin();
    return ub - lb;
}

void solve() {
    int n; cin >> n;

    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<int>> adj(n+1);
    vector<pair<int,int>> edge(n-1);

    for (int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        edge[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    timer = 1;
    divisor.clear();

    euler_start.assign(n+1, 0);
    euler_end.assign(n+1, 0);
    euler(1, 0, adj);

    process(a, n);

    int q; cin >> q;
    while (q--) {
        int id, k; cin >> id >> k;
        auto [u, v] = edge[id - 1];

        int cu = range_count(euler_start[u], euler_end[u], k);
        int cv = range_count(euler_start[v], euler_end[v], k);

        int tot = (int)divisor[k].size();

        if (cu < cv) cout << max(cu, tot - cu) << '\n';
        else cout << max(cv, tot - cv) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}