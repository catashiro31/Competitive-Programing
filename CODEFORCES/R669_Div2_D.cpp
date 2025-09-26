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
    vector<int> h(n);
    for (int &x : h) cin >> x;
    vector<int> dp(n,INT_MAX);
    deque<int> dq1, dq2;
    for (int i = 0; i < n; i++) {
        if (i == 0) dp[i] = 0;
        else {
            while(!dq1.empty() && h[dq1.back()] <= h[i]) {
                dp[i] = min(dp[i],dp[dq1.back()]+1);
                dq1.pop_back();
            }
            while(!dq2.empty() && h[dq2.back()] >= h[i]) {
                dp[i] = min(dp[i],dp[dq2.back()]+1);
                dq2.pop_back();
            }
        }
        dq1.push_back(i);
        dq2.push_back(i);
    }
    cout << dp[n-1];
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