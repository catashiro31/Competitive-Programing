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
    int n, k; cin >> n >> k;
    vector<pair<int,pair<int,int>>> slp(k+1);
    for (int i = 1; i <= k; i++) cin >> slp[i].se.fi >> slp[i].se.se >> slp[i].fi;
    sort(all(slp));
    vector<int> dp(n+1,0);
    for (int i = 1; i <= k; i++) {
        int best = INT_MIN;
        int dec = slp[i].se.se * slp[i].se.fi, inc = 0;
        for (int j = slp[i].fi + slp[i].se.fi - 1; j >= slp[i].fi; j--) {
            if (j >= slp[i].se.fi) best = max(best, dp[j-slp[i].se.fi] + inc);
            if (j <= n) dp[j] = max(dp[j], best + dec);
            dec -= slp[i].se.se;
            inc += slp[i].se.se;
        }
        for (int j = 2; j <= n; j++) dp[j] = max(dp[j], dp[j-1]);
    }
    cout << dp[n];
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