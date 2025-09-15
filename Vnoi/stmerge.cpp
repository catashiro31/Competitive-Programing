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
const string NoF = "Name_of_File";
    
void solve() {
    int m, n; cin >> m >> n;
    vector<vector<ll>> arr(m+1,vector<ll>(n+1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) cin >> arr[i][j];
    }
    vector<vector<pair<ll,ll>>> dp(m+1,vector<pair<ll,ll>>(n+1,{LLONG_MAX,LLONG_MAX}));
    dp[0][0] = {LLONG_MAX, LLONG_MAX};
    for (int i = 1; i <= n; i++) dp[0][i] = {LLONG_MAX,0};
    for (int i = 1; i <= m; i++) dp[i][0] = {0,LLONG_MAX};
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            pair<ll,ll> up = dp[i-1][j], left = dp[i][j-1];
            if (up.fi != LLONG_MAX) dp[i][j].fi = min(dp[i][j].fi, up.fi);
            if (up.se != LLONG_MAX) dp[i][j].fi = min(dp[i][j].fi, up.se+arr[i][j]);
            if (left.fi != LLONG_MAX) dp[i][j].se = min(dp[i][j].se, left.fi+arr[i][j]);
            if (left.se != LLONG_MAX) dp[i][j].se = min(dp[i][j].se, left.se);
        } 
    }
    cout << min(dp[m][n].fi, dp[m][n].se) << endl;
}
    
int main() {
#ifndef ONLINE_JUDGE
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
}