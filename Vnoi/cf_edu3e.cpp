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
const int LOG = 20;
const string NoF = "Name_of_File";
int par[MAXN], depth[MAXN];
vector<pair<int,ll>> nxt[MAXN]; 
int up[MAXN][LOG];
ll mx[MAXN][LOG];

int _find(int u) {
    if (u == par[u]) return u;
    return par[u] = _find(par[u]);
}

bool _union(int u, int v, ll w) {
    int pu = _find(u), pv = _find(v);
    if (pu == pv) return false;
    if (pu < pv) par[pv] = pu;
    else par[pu] = pv;
    return true;
}

void dfs(int u, int p) {
    up[u][0] = p;
    for (int k = 1; k < LOG; ++k) {
        up[u][k] = up[up[u][k-1]][k-1];
        mx[u][k] = max(mx[u][k-1], mx[up[u][k-1]][k-1]);
    }
    for (auto [v,w] : nxt[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        mx[v][0] = w;
        dfs(v, u);
    } 
}

ll max_on_path(int u, int v) {
    ll ans = 0;
    if (depth[u] < depth[v]) swap(u,v);
    
    int diff = depth[u] - depth[v];
    for (int k = LOG-1; k >= 0; k--) {
        if (diff & (1 << k)) {
            ans = max(ans,mx[u][k]);
            u = up[u][k];
        }
    }

    if (u == v) return ans;

    for (int k = LOG-1; k >= 0; --k) {
        if (up[u][k] != up[v][k]) {
            ans = max(ans,mx[u][k]);
            ans = max(ans,mx[v][k]);
            u = up[u][k];
            v = up[v][k];
        }
    }

    ans = max(ans, mx[u][0]);
    ans = max(ans, mx[v][0]);
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<pair<int,int>,ll>> adjList(m);
    priority_queue<pair<ll,pair<int,int>>, vector<pair<ll,pair<int,int>>>, greater<pair<ll,pair<int,int>>>> pq;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; 
        ll w; cin >> w;
        --u, --v;
        adjList[i] = {{u,v},w};
        pq.push({w,{u,v}});
    }
    ll val = 0;
    for (int i = 0; i < n; i++) par[i] = i;
    while (!pq.empty()) {
        auto [w,uv] = pq.top(); pq.pop();
        auto [u,v] = uv;
        if (_union(u,v,w)) {
            val += w;
            nxt[u].psb({v,w});
            nxt[v].psb({u,w});
        }
    }

    depth[0] = 0, mx[0][0] = 0;
    dfs(0,-1);
    for (int i = 0; i < m; i++) {
        auto [uv, w] = adjList[i];
        auto [u,v] = uv;
        cout << val + w - max_on_path(u,v) << endl;
    } 
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
