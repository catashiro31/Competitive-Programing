#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;

struct DSU {
    int maxn;
    vector<int> parent, sz;

    DSU(int n) : maxn(n), parent(n), sz(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int Find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = Find(parent[u]); 
    }

    bool Union(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (u == v) return false; 
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        parent[v] = u;
        return true;
    }
};

void solve() {
	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}