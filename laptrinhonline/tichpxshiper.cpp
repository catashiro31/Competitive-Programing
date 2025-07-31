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
int c[MAXN];
int Find(int u) {
    if (c[u] == u) return u;
    return c[u] = Find(c[u]);
}
void solve() {
    int n; cin >> n;
    for (int i = 0; i < MAXN; i++) c[i] = i;
    vector<pair<int,int>> arr(n);
    for (auto &[t,v] : arr) cin >> t >> v;
    sort(all(arr),[](auto a, auto b) {
        return a.se > b.se;
    });
    ll kq = 0;
    for (auto [t,v] : arr) {
        int p = Find(t);
        if (p > 0) {
            kq += v;
            c[p] = p-1;
        }
    }
    cout << kq;
}
    
int main() {
#ifndef ONLINE_JUDGE
    freopen((NoF + ".in").c_str(), "r", stdin);
    freopen((NoF + ".out").c_str(), "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}