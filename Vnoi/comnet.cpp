#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long

struct edge {
    int u, v, w, id, b;
};

int findp(vector<int>& par, int u) {
    if (par[u] == u) return u;
    return par[u] = findp(par, par[u]);
}
void unitep(vector<int>& par, int u, int v) {
    int pu = findp(par, u), pv = findp(par, v);
    if (pu == pv) return;
    par[pv] = pu;
}

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
        edge x; cin >> x.u >> x.v >> x.w;
        --x.u; --x.v; x.id = i; x.b = -1;
        edges.psb(x);
    }

    vector<edge> orig = edges;
    vector<int> query(q);
    vector<vector<int>> updated_edge_ids(q); 

    for (int i = 0; i < q; i++) {
        int k, s; cin >> k >> s;
        --k; query[i] = k;
        for (int j = 0; j < s; j++) {
            int t, c; cin >> t >> c;
            --t;
            updated_edge_ids[i].psb(t);
            edge x = orig[t];
            x.b = i; x.w = c;
            edges.psb(x);
        }
    }

    sort(all(edges),(auto &a, auto &b){
        return a.w < b.w;
    });

    vector<int> par(n);
    for (int i = 0; i < q; i++) {
        vector<bool> is_updated(m, false);
        for(int id : updated_edge_ids[i]) {
            is_updated[id] = true;
        }

        bool connected = false;
        edge target = orig[query[i]];
        long long len = LLONG_MAX, lim = LLONG_MAX;
        
        iota(all(par),0);

        for (const edge &x : edges) {
            // --- SỬA LỖI LỌC CẠNH ---
            // Điều kiện lọc cạnh đúng:
            // 1. Cạnh này là bản cập nhật cho truy vấn hiện tại (x.b == i)
            // 2. Hoặc cạnh này là cạnh gốc (x.b == -1) VÀ nó không bị cập nhật trong truy vấn này
            bool is_relevant = (x.b == i) || (x.b == -1 && !is_updated[x.id]);
            if (!is_relevant) continue;

            if (x.id == target.id) {
                lim = x.w;
                break;
            }

            if (findp(par, x.u)!= findp(par, x.v)) {
                unitep(par, x.u, x.v);
                if (!connected && findp(par, target.u) == findp(par, target.v)) {
                    len = x.w;
                    connected = true;
                }
            }
        }
        
        if (len < lim) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}