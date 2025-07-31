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
    
void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    vector<int> p;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            p.psb(i);
            a[i] = -1e13;
        }
    }
    ll cmax = LLONG_MIN;
    set<ll> st; st.insert(0);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + a[i];
        cmax = max(sum-*(st.begin()),cmax);
        st.insert(sum);
    }
    if (cmax > k) cout << "NO" << endl;
    else {
        if (sz(p) == 0) {
            if (cmax == k) {
                cout << "YES" << endl;
                for (ll x : a) cout << x << " ";
                cout << endl;
            } else cout << "NO" << endl;
        } else {
            ll smin = 0, tmp = 0, smax = LLONG_MIN;
            for (int i = 0; i < p[0]; i++) tmp += a[i], smin = min(smin,tmp);
            for (int i = p[0]; i < n; i++) tmp += a[i], smax = max(smax,tmp-smin);
            a[p[0]] += (k-smax);
            cout << "YES" << endl;
            for (ll x : a) cout << x << " ";
            cout << endl;
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