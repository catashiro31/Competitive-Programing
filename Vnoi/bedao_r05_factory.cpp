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
bool check(int m,int n, int sum[], int k) {
    vector<int> dp((1<<n),INT_MAX);
    dp[0] = 0;
    for (int mask = 1; mask < (1<<n); mask++) {
        if (sum[mask] <= m) dp[mask] = 1;
        for (int submask = mask; submask > 0; submask = (submask-1) & mask) {
            if (dp[submask] == INT_MAX) continue;
            if (sum[mask^submask] <= m) dp[mask] = min(dp[mask],dp[submask]+1);
        }
    }
    return dp[(1<<n)-1] <= k;
}

void solve() {
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum[1<<n];
    for (int mask = 0; mask < (1<<n); mask++) {
        sum[mask] = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1<<i)) sum[mask] += a[i];
        } 
    }
    int l = 0, r = sum[(1<<n)-1], kq = INT_MAX;
    while (l <= r) {
        int m = (l+r)/2;
        if (check(m,n,sum,k)) {
            kq = min(kq,m);
            r = m-1;
        } else l = m+1;
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