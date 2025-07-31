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
    vector<vector<ll>> val(n,vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> val[i][j];
    }
    vector<ll> cost((1<<n),0);
    for (int mask = 0; mask < (1<<n); mask++) {
        for (int i = 0; i < n-1; i++) {
            if (((mask>>i)&1) == 0) continue;
            for (int j = i+1; j < n; j++) {
                if (((mask>>j)&1) == 0) continue;
                cost[mask] += val[i][j];
            }
        } 
    }
    vector<ll> dp((1<<n),0);
    for (int mask = 0; mask < (1<<n); mask++) {
        int remain = ((1<<n)-1) ^ mask;
        for (int submask = remain; submask > 0; submask = (submask-1)&remain) {
            dp[mask|submask] = max(dp[mask|submask], dp[mask]+cost[submask]);
        }
    }
    cout << dp[(1<<n)-1] << endl;
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