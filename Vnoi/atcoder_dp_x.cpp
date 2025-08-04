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
    vector<ll> w(n), s(n), v(n);
    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        idx[i] = i;
        cin >> w[i] >> s[i] >> v[i];
    }
    sort(all(idx),[&](auto &a, auto &b){
        return w[a]+s[a] < w[b]+s[b];
    });
    vector<ll> dp(2e5+1,0);
    for (int x = 0; x < n; x++) {
        int i = idx[x];
        for (ll j = s[i]+w[i]; j >= w[i]; j--) {
            dp[j] = max(dp[j],dp[j-w[i]] + v[i]);
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