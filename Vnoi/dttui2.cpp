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
    int n, m; cin >> n >> m;
    vector<pair<int,pair<int,int>>> wva(n);
    for (int i = 0; i < n; i++) cin >> wva[i].fi >> wva[i].se.fi >> wva[i].se.se;
    vector<pair<int,int>> items;
    for (int i = 0; i < n; i++) {
        for (int j = 0; (1 << j) <= wva[i].se.se; j++) {
            wva[i].se.se -= (1<<j);
            items.psb({(1<<j)*wva[i].fi,wva[i].se.fi*(1<<j)});
        }
        if (wva[i].se.se == 0) continue;
        items.psb({wva[i].se.se*wva[i].fi,wva[i].se.fi*wva[i].se.se});
    }
    vector<int> dp(m+1,INT_MIN);
    dp[0] = 0;
    for (int i = 0; i < sz(items); i++) {
        for (int j = m-items[i].fi; j >= 0; j--) {
            if (dp[j] == INT_MIN) continue;
            dp[j+items[i].fi] = max(dp[j+items[i].fi],dp[j]+items[i].se);
        }
    }
    cout << *max_element(all(dp));
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