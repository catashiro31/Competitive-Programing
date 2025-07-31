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
int par[MAXN];
int Find(int u) {
    if (par[u] == u) return u;
    return par[u] = Find(par[u]);
}
void Union(int u, int v) {
    int pu = Find(u), pv = Find(v);
    if (pu == pv) return;
    if (pu < pv) par[pv] = pu;
    else par[pu] = pv;
    return;
}
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) par[i] = i;
    int arr[4];
    arr[0] = INT_MIN, arr[1] = INT_MAX, arr[2] = INT_MIN, arr[3] = INT_MAX;
    while (m--) {
        int x; cin >> x;
        if (x <= (n+1)/2) arr[0] = max(arr[0],x), arr[1] = min(arr[1],x);
        else arr[2] = max(arr[2],x), arr[3] = min(arr[3],x);
    }
    for (int i = 0; i < 4; i++) {
        int u = 1, v = n;
        while (u <= v) {
            if (u == arr[i]) u++;
            if (v == arr[i]) v--;
            Union(u,v);
            u++, v--;
        }
    } 
    for (int i = 1; i <= n; i++) cout << Find(i) << " ";
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