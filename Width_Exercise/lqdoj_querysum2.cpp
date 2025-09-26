#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int MAXN = 1e5+5;
void update(vector<ll> &BIT, int x, ll val) {
    for (; x < BIT.size(); x += x&(-x)) BIT[x] += val;
}

ll get(const vector<ll> &BIT, int x) {
    ll res = 0;
    for (; x; x -= x&(-x)) res += BIT[x];
    return res;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> diff(n+1);
    diff[1] = a[1];
    for (int i = 2; i <= n; i++) diff[i] = a[i] - a[i-1];
    vector<ll> BIT1(n+1), BIT2(n+1);
    for (int i = 1; i <= n; i++) {
        update(BIT1, i, 1LL * (n - i + 1) * diff[i]);
        update(BIT2, i, diff[i]);
    }
    while(q--) {
        int t; cin >> t;
        if (t == 1) {
            int u, v; cin >> u >> v;
            ll x; cin >> x;
            update(BIT1,u,1LL*(n-u+1)*x);
            update(BIT1,v+1,-1LL*(n-v)*x);
            update(BIT2,u,x);
            update(BIT2,v+1,-x);
        } else {
            int u, v; cin >> u >> v;
            ll r = get(BIT1,v) - 1LL*(n-v)*get(BIT2,v);
            ll l = get(BIT1,u-1) - 1LL*(n-u+1)*get(BIT2,u-1);
            cout << r - l << endl;
        }
    }
    return;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie();
    solve();
}
