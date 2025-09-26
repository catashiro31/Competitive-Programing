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
    vector<ll> a(n), b(n);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;
    ll cmax = max(*max_element(all(a)), *max_element(all(b)));
    ll sum = 0;
    for (ll i = 0; i < n; i++) sum += 1LL*a[i]*b[i];
    ll kq = sum + k*cmax;
    for (ll i = 0; i < n; i++) {
        ll val = a[i]+b[i]+k;
        if (a[i] + k < b[i]) {
            kq = max(kq,sum - a[i]*b[i] + (a[i]+k)*b[i]);
        } else if (b[i] + k < a[i]){
            kq = max(kq,sum - a[i]*b[i] + (b[i]+k)*a[i]);
        } else {
            ll tmp = val/2LL;
            kq = max(kq, sum-a[i]*b[i]+tmp*(val-tmp));
        }
    }
    cout << kq;
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