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
    int m; cin >> m;
    map<int,int> freq;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    int n = sz(freq);
    vector<int> values;
    for (auto [v,f] : freq) values.psb(v); 
    int MAX_MASK = 1 << 10;
    ll dp[n][MAX_MASK];
    for (int mask = 0; mask < MAX_MASK; mask++) dp[0][mask] = LLONG_MAX;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < MAX_MASK; mask++) {
            if (dp[i][mask] < 0) continue;
            int shift = 0;
            if (i == 0) shift = 0;
            else {
                int gap = values[i] - values[i-1];
                if (gap > 9) shift = 0;
                else {
                    shift = mask << gap;
                    shift = shift & (MAX_MASK-1);
                }
            }
            int new_mask = (shift << 1) & (MAX_MASK - 1);
            dp[i+1][new_mask] = min(dp[i+1][new_mask], dp[i][mask]);

            bool can_keep = true;
            int d[3] = {1, 8, 9};
            for (int x : d) {
                if (x <= 9 && (shift & (1 << x) != 0)) {
                    can_keep = false;
                    break;
                }
            }
            if (can_keep) {
                new_mask = ((shift << 1) | 1) & (MAX_MASK - 1);
                dp[i+1][new_mask] = max(dp[i+1][new_mask], dp[i][mask] + freq[values[i]]);
            }
        }
    }
    int kq = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < MAX_MASK; mask++) kq = max(kq, dp[i][mask] + freq[values[i]]);
    }
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