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
    int x[n+1], y[n+1];
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    vector<vector<int>> dp(n/2+5,vector<int>(n/2+5,INT_MAX));
    dp[0][0] = 0;
    for (int i = 0; i <= n/2; i++) {
        for (int j = 0; j <= i; j++) {
            if (dp[i][j] == INT_MAX) continue;
            int cur = i+j+1;
            if (cur <= n && i <= n/2) dp[i+1][j] = min(dp[i+1][j],dp[i][j]+y[cur]);
            if (j+1 <= i) dp[i][j+1] = min(dp[i][j+1],dp[i][j]+x[cur]);
        }
    }
    cout << dp[n/2][n/2];
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