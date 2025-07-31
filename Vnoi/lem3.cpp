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
    int n; cin >> n;
    vector<vector<int>> board(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }
    vector<vector<int>> dp((1<<n),vector<int>(n,INT_MAX));
    for (int i = 0; i < n; i++) dp[(1<<i)][i] = 0;
    for (int mask = 0; mask < (1<<n); mask++) {
        for (int u = 0; u < n; u++) {
            if (dp[mask][u] == INT_MAX) continue;
            for (int v = 0; v < n; v++) {
                if (mask&(1<<v)) continue;
                int new_mask = mask|(1<<v);
                dp[new_mask][v] = min(dp[new_mask][v],dp[mask][u]+board[u][v]); 
            }
        }
    }
    int kq = INT_MAX;
    for (int i = 0; i < n; i++) kq = min(kq,dp[(1<<n)-1][i]);
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