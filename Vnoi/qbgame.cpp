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
    ll arr[8][n];
    ll cmax = LLONG_MIN;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            cmax = max(cmax,arr[i][j]);
        }
    }
    if (cmax <= 0) {cout << cmax; return;}
    vector<int> sa;
    for (int i = 0; i < (1<<8); i++) {
        bool check = false;
        for (int j = 1; j < 8; j++) {
            if (((i>>(j-1))&1) && ((i>>j)&1)) check = true;
        }
        if (!check) sa.psb(i);
    }
    ll dp[1<<8][n];
    for (int i = 0; i < n; i++) {
        vector<ll> val((1<<8));
        for (int x : sa) {
            val[x] = 0;
            for (int j = 0; j < 8; j++) {
                if ((x>>j)&1) val[x] += arr[j][i];
            }
        }
        for (int x : sa) {
            dp[x][i] = val[x];
            if (i == 0) continue;
            for (int y : sa) {
                if ((x&y)==0) dp[x][i] = max(dp[x][i],dp[y][i-1]+val[x]);
            }
        }
    }
    ll kq = INT_MIN;
    for (int x : sa) kq = max(kq,dp[x][n-1]);
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