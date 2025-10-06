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
    int n; cin >> n;
    vector<int> top, bot;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x) top.psb(x);
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x) bot.psb(x);
    }
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(sz(top)+5,vector<int>(sz(bot)+5,INT_MIN)));
    dp[0][0][0] = 0;
    for (int i = 0; i <= n-1; i++) {
        for (int j = 0; j <= sz(top); j++) {
            for (int k = 0; k <= sz(bot); k++) {
                if (dp[i][j][k] == INT_MIN) continue;
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                if (j < sz(top)) dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k]);
                if (k < sz(bot)) dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k]);
                if (j < sz(top) && k < sz(bot)) dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1], dp[i][j][k] + top[j] * bot[k]);
            }
        }
    }
    cout << dp[n][sz(top)][sz(bot)];
}
    
int main() {
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}