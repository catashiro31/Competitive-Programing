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
const int MOD = 20122007;
const int MAXN = 2e5+1;
const string NoF = "Name_of_File";
ll pow_mod(ll base, ll exp) {
    ll res = 1;
    while(exp) {
        if (exp&1) res = (res*base)%MOD;
        base = (base*base)%MOD;
        exp /= 2;
    }
    return res;
}
void solve() {
    ll a; cin >> a;
    vector<ll> uoc;
    for (ll i = 1; i*i <= a; i++) {
        if (a%i == 0) {
            uoc.psb(i);
            if (a/i != i) uoc.psb(a/i);
        }
    }
    ll kq = 1;
    for (ll x : uoc) kq = (kq * (pow_mod(3,x) -1 + MOD)%MOD)%MOD;
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