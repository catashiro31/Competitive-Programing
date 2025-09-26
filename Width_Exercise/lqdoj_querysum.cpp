#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void update(vector<ll> &BIT, ll x, ll val) {
    for (; x < BIT.size(); x += x&(-x)) BIT[x] += val;
}

ll get(const vector<ll> &BIT, ll x) {
    ll res = 0;
    for (; x; x -= x&(-x)) res += BIT[x];
    return res;
}

int main() {
    ll n, q; cin >> n >> q;
    vector<ll> BIT(n+5,0);
    for (ll i = 1; i <= n; i++) {
        ll x; cin >> x;
        update(BIT,i,x);
    }
    while (q--) {
        ll t; cin >> t;
        if (t == 1) {
            ll x, val; cin >> x >> val;
            update(BIT,x,val);
        } else {
            ll u, v; cin >> u >> v;
            if (u == 1) cout << get(BIT,v) << '\n';
            else cout << get(BIT,v) - get(BIT,u-1) << '\n';
        }
    }
}
