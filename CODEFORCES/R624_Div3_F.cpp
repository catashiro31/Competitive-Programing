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

void update(vector<ll> &BIT, int x, ll val) {
    for (; x < sz(BIT); x+=x&(-x)) BIT[x]+=val;
}

ll get(const vector<ll> &BIT, int x) {
    ll res = 0;
    for (; x > 0; x-=x&(-x)) res+=BIT[x];
    return res;
}

void solve() {
    int n; cin >> n;
    vector<pair<ll,ll>> xv(n);
    for (int i = 0; i < n; i++) cin >> xv[i].fi;
    for (int i = 0; i < n; i++) cin >> xv[i].se;
    sort(all(xv));
    vector<ll> base;
    for (int i = 0; i < n; i++) base.psb(xv[i].se);
    sort(all(base));
    base.erase(unique(all(base)),base.end());
    auto rank = [&](ll v) {
        return int(lb(all(base),v)-base.begin())+1;
    };
    vector<ll> BIT1(sz(base)+5,0), BIT2(sz(base)+5,0);
    ll kq = 0;
    for (int i = 0; i < n; i++) {
        ll x = xv[i].fi, v = xv[i].se;
        int rank_v = rank(v);
        kq += 1LL*x*get(BIT1,rank_v) - get(BIT2,rank_v);
        update(BIT1,rank_v,1);
        update(BIT2,rank_v,x);
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