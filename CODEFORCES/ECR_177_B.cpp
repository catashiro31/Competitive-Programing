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
    ll n, k; cin >> n >> k;
    ll x; cin >> x;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    vector<ll> prefix(n);
    prefix[0] = a[0];
    for (ll i = 1; i < n; i++) prefix[i] = prefix[i-1] + a[i];
    vector<ll> step(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        ll tmp = x / prefix[n-1];
        step[i] = tmp * n;
        ll val = x - tmp * prefix[n-1];
        if (val > 0) {
            auto it = lb(all(prefix),val+sum);
            if (it == prefix.end()) {
                val -= prefix[n-1] - sum;
                step[i] += n-i;
                ll p = lb(all(prefix),val) - prefix.begin();
                step[i] += p+1;
            } else step[i] += it-prefix.begin()-i+1;
        }
        sum += a[i];
    }
    ll ml = n*k;
    ll kq = 0;
    for (ll i = 0; i < n; i++) {
        ll mp = ml-step[i];
        if (mp < i) continue;
        kq += (mp-i)/n+1;
    }
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