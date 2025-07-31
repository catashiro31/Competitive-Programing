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
    
void solve() {
    int n, k; cin >> n >> k;
    vector<int> w(n);
    for (int &x : w) cin >> x;
    vector<int> adjList[n];
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adjList[u].psb(v);
        adjList[v].psb(u);
    }
    ll l = 0, r = 1e18;
    while (l <= r) {
        ll m = (l+r)/2;
        if (check()) , kq = m, r = m-1;
        else l = m+1;
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