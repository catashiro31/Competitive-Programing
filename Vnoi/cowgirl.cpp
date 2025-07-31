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
bool check(int a, int b, int n) {
    for (int i = 1; i < n; ++i) {
        int x1 = (a >> (i - 1)) & 1;
        int x2 = (a >> i) & 1;
        int y1 = (b >> (i - 1)) & 1;
        int y2 = (b >> i) & 1;
        if (x1 == x2 && x2 == y1 && y1 == y2) return false;
    }
    return true;
}

void solve() {
    int m, n; cin >> m >> n;
    if (m < n) swap(m,n);
    vector<vector<ll>> dp(m,vector<ll>((1<<n),0));
    for (int i = 0; i < (1 << n); i++) dp[0][i] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < (1 << n); j++) {
            if (dp[i-1][j] == 0) continue;
            for (int k = 0; k < (1 << n); k++) {
                if (check(j,k,n)) dp[i][k] += dp[i-1][j];
            }
        }
    }
    ll kq = 0;
    for (int i = 0; i < (1 << n); i++) kq += dp[m-1][i];
    cout << kq << endl;
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