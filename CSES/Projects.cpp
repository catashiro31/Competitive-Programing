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
    vector<pair<pair<ll,ll>,ll>> arr(n);
    vector<ll> cal(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].fi.fi >> arr[i].fi.se >> arr[i].se;
        cal[i] = arr[i].fi.se;
    }
    sort(all(arr));
    sort(all(cal));
    vector<ll> dp(n,0);
    ll cmax = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while(j < n && cal[j] < arr[i].fi.fi) cmax = max(cmax,dp[j]), j++;
        int p = lb(all(cal),arr[i].fi.se)-cal.begin();
        dp[p] = max(dp[p],cmax+arr[i].se);
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