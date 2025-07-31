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
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<vector<int>> dp(n+1,vector<int>(k,INT_MIN));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
            if (dp[i-1][j] == INT_MIN) continue;
            dp[i][(j+a[i-1])%k] = max(dp[i][(j+a[i-1])%k],dp[i-1][j]+1);
        }
    }
    cout << dp[n][0];
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