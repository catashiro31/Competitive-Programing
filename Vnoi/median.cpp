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
const int MOD = 65536;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";
    
ll solve() {
    ll seed, mul, add, n, k; cin >> seed >> mul >> add >> n >> k;
    vector<ll> a(n);
    a[0] = seed;
    for (ll i = 1; i < n; i++) a[i] = (a[i-1] * mul + add)%MOD;
    OST<pair<ll,ll>> ost;
    ll kq = 0;
    for (ll i = 0; i < n; i++) {
        ost.insert({a[i],i});
        if (i >= k) {
            auto it = ost.lower_bound({a[i-k],LLONG_MIN});
            ost.erase(it);
        }
        if (i >= k-1) kq += (*ost.find_by_order((k+1)/2-1)).fi; 
    }
    return kq;
}
    
int main() {
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}