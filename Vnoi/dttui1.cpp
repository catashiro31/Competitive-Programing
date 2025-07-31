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
pair<ll,ll> cal = {0,0};
void Try(int i, int n, const vector<pair<ll,ll>> &arr, vector<pair<ll,ll>> &stored) {
    if (i == n) {
        stored.psb(cal);
        return;
    }
    cal = {cal.fi+arr[i].fi, cal.se+arr[i].se};
    Try(i+1,n,arr,stored);
    cal = {cal.fi-arr[i].fi, cal.se-arr[i].se};
    Try(i+1,n,arr,stored);
}
void solve() {
    ll n, M; cin >> n >> M;
    vector<pair<ll,ll>> arr(n);
    for (auto &[u,v] : arr) cin >> u >> v;
    ll sz = max(n/2,n-n/2);
    vector<pair<ll,ll>> stored1;
    Try(0,sz,arr,stored1);
    vector<pair<ll,ll>> stored2;
    Try(sz,n,arr,stored2);
    sort(all(stored2));
    vector<ll> W(sz(stored2)), Vmax(sz(stored2));
    ll cmax = LLONG_MIN;
    for (int i = 0; i < sz(stored2); i++) {
        W[i] = stored2[i].fi;
        cmax = max(cmax,stored2[i].se);
        Vmax[i] = cmax;
    }
    ll kq = 0;
    for (auto [w,v] : stored1) {
        if (w > M) continue;
        ll tmp = M-w;
        int p = ub(all(W),tmp) - W.begin();
        kq = max(kq,v+Vmax[p-1]);
    }
    cout << kq;
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