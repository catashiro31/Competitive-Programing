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
ll query1(ll n, ll l, ll r, ll u, ll v, ll x) {
    if (!n) return x;
    ll step = pow(2,n-1);
    if (l <= u && u < l+step && r <= v && v < r+step) {
        return query1(n-1,l,r,u,v,x);
    }
    if (l <= u && u < l+step && r+step <= v && v < r+2*step) {
        return query1(n-1,l,r+step,u,v,x+3*pow(2,2*(n-1)));
    }
    if (l+step <= u && u < l+2*step && r <= v && v < r+step) {
        return query1(n-1,l+step,r,u,v,x+2*pow(2,2*(n-1)));
    }
    if (l+step <= u && u < l+2*step && r+step <= v && v < r+2*step) {
        return query1(n-1,l+step,r+step,u,v,x+pow(2,2*(n-1)));
    }
    return 0;
}
pair<ll,ll> query2(ll n, ll x, ll l, ll r, ll u, ll v) {
    if (!n) return {u,v};
    ll step = (r-l+1)/4;
    if (l <= x && x < l+step) {
        return query2(n-1,x,l,l+step-1,u,v);
    }
    if (l+step <= x && x < l+2*step) {
        return query2(n-1,x,l+step,l+2*step-1,u+pow(2,n-1),v+pow(2,n-1));
    }
    if (l+2*step <= x && x < l+3*step) {
        return query2(n-1,x,l+2*step,l+3*step-1,u+pow(2,n-1),v);
    } 
    if (l+3*step <= x && x <= r) {
        return query2(n-1,x,l+3*step,r,u,v+pow(2,n-1));
    }
    return {0,0};
}
void solve() {
    ll n; cin >> n;
    int q; cin >> q;
    while (q--) {
        string typ; cin >> typ;
        if (typ == "->") {
            ll u, v; cin >> u >> v;
            cout << query1(n,1,1,u,v,1) << endl;
        } else {
            ll x; cin >> x;
            auto ans = query2(n,x,1,pow(2,2*n),1,1);
            cout << ans.fi << " " << ans.se << endl;
        }
    }
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