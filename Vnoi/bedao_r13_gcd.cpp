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
vector<ll> snt, tmp;
ll kq = LLONG_MAX;
int gcd(ll a, ll b) {
    if (!b) return a;
    return gcd(b,a%b);
}
void Try(int i, vector<bool> &c, vector<ll> a) {
    if (!i) {
        ll temp = 1;
        for (ll k : tmp) temp *= k;
        bool check = true;
        for (ll k : a) if (gcd(temp,k) == 1) check = false;
        if (check) kq = min(kq,temp); 
        return;
    }
    for (int j = 0; j < sz(snt); j++) {
        if (c[j]) continue;
        if (!tmp.empty() && snt[j] <= tmp[sz(tmp)-1]) continue;
        c[j] = true;
        tmp.psb(snt[j]);
        Try(i-1,c,a);
        tmp.ppb();
        c[j] = false;
    }
}
void solve() {
    for (ll i = 2; i <= 50; i++) {
        bool c = false;
        for (ll j = 2; j*j <= i; j++) {
            if (i % j == 0) c = true;
        }
        if (c) continue;
        snt.psb(i);
    }
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    vector<bool> c(sz(snt),false);
    for (int i = 1; i <= sz(snt); i++) Try(i,c,a);
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