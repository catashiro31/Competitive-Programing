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
const int MOD = 1e9;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}
void solve() {
    int m, n; cin >> m >> n;
    vector<vector<ll>> val(m,vector<ll>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> val[i][j];
    }
    vector<vector<ll>> dp(m,vector<ll>(n,0));
    for (int j = 0; j < n-1; j++) {
        for (int i = 0; i < m; i++) {
            if (j == 0) dp[i][j]++;
            for (int k = i; k < m; k++) {
                for (int h = j; h < n; h++) {
                    if (i+j < k+h && gcd(val[i][j],val[k][h]) > 1) dp[k][h] = (dp[k][h]+dp[i][j])%MOD;
                }
            }
        }
    }
    ll kq = 0;
    for (int i = 0; i < m; i++) kq = (kq+dp[i][n-1])%MOD;
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