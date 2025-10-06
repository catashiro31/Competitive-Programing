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
    vector<string> dstr(m);
    for (string &x : dstr) cin >> x;
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (dstr[i-1][j-1] == '1') continue;
            dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1])) + 1;
        }
    }
    ll kq = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) kq += dp[i][j];
    }
    cout << kq;
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