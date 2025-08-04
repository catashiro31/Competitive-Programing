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
const int MAXN = 2e5 + 10;
const string NoF = "Name_of_File";
ll fact[MAXN], inv[MAXN];
ll inv_modulo(ll base, ll exp) {
    ll res = 1LL;
    while (exp) {
        if (exp&1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
void init(void) {
    fact[0] = 1;
    inv[0] = inv_modulo(fact[0], MOD - 2);
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
        inv[i] = inv_modulo(fact[i],MOD-2);
    }
}
ll combination(ll n, ll k) {
    ll res = fact[n];
    res = (res * inv[k]) % MOD;
    res = (res * inv[n-k]) % MOD;
    return res;
}
void solve() {
    ll h, w; cin >> h >> w;
    ll n; cin >> n;
    vector<pair<ll,ll>> blocked(n);
    for (auto &[r,c] : blocked) cin >> r >> c;
    sort(all(blocked),[](auto &a, auto &b){
        return a.fi + a.se < b.fi + b.se;
    });
    init();
    vector<ll> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = combination(blocked[i].fi-1 + blocked[i].se-1, blocked[i].fi-1);
        for (int j = 0; j < i; j++) {
            if (blocked[j].fi > blocked[i].fi || blocked[j].se > blocked[i].se) continue;
            ll val = combination(blocked[i].fi - blocked[j].fi + blocked[i].se - blocked[j].se, blocked[i].fi - blocked[j].fi);
            val = (val * dp[j]) % MOD;
            dp[i] = (dp[i] - val + MOD) % MOD;
        }
    }
    ll kq = combination(h-1 + w-1, h-1);
    for (int i = 0; i < n; i++) {
        ll val = combination(h-blocked[i].fi + w-blocked[i].se, h-blocked[i].fi);
        val = (val * dp[i]) % MOD;
        kq = (kq - val + MOD) % MOD;
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
    int t = 1;
    while(t--) {
        solve();
    }
}