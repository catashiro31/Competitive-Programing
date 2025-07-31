#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX_NODES = 1e5+5;
const int LOG_MAX = 17;

vector<int> adj[MAX_NODES];
int anc[MAX_NODES][LOG_MAX];
int nod_D[MAX_NODES];
int n, q;

void dfs(int cur_N, int par_N) {
    anc[cur_N][0] = par_N;
    
    for (int i = 1; i < LOG_MAX; ++i) {
        if (anc[cur_N][i - 1] != -1) {
            anc[cur_N][i] = anc[anc[cur_N][i - 1]][i - 1];
        } else {
            anc[cur_N][i] = -1;
        }
    }
    
    for (int z : adj[cur_N]) {
        if (z != par_N) {
            nod_D[z] = nod_D[cur_N] + 1;
            dfs(z, cur_N);
        }
    }
}

int lca(int u, int v) {
    if (nod_D[u] < nod_D[v]) swap(u, v);

    for (int i = LOG_MAX - 1; i >= 0; --i) {
        if (nod_D[u] - (1 << i) >= nod_D[v]) {
            u = anc[u][i];
        }
    }

    if (u == v) return u;

    for (int i = LOG_MAX - 1; i >= 0; --i) {
        if (anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }

    return anc[u][0];
}

void solve() {
    cin >> n >> q;
    
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(anc, -1, sizeof(anc));
    nod_D[1] = 0;
    dfs(1, -1);

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if(nod_D[lca(x, y)] + nod_D[lca(y, z)] == nod_D[lca(x, z)] + nod_D[y] 
            || nod_D[lca(y, z)] + nod_D[lca(x, y)] == nod_D[lca(x, z)] + nod_D[z]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}