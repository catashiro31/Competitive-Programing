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
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";
int Find(int u, vector<int> &par) {
    if (par[u] == u) return u;
    return par[u] = Find(par[u],par);
}
bool Union(int u, int v, vector<int> &par) {
    int pu = Find(u,par), pv = Find(v,par);
    if (pu == pv) return false;
    if (pu < pv) par[pv] = pu;
    else par[pu] = pv;
    return true;
}
void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int,pair<int,int>>> arr;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        arr.psb({w,{u,v}});
    }
    sort(all(arr));
    vector<int> par(n);
    for (int i = 0; i < n; i++) par[i] = i; 
    int kq = INT_MIN;
    for (int i = 0 ; i < m; i++) {
        auto [w,uv] = arr[i];
        auto [u,v] = uv;
        if (Union(u,v,par)) kq = max(kq,w);
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