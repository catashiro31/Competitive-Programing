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
    
void solve() {
    int n; cin >> n;
    vector<ll> b(2*n);
    for (ll &x : b) cin >> x;
    sort(all(b));
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < 2*n; i++) {
        if (i < n-1) sum1 += b[i];
        else sum2 += b[i];
    }
    ll val = sum2 - sum1;
    vector<ll> a(2*n+1);
    int j = 2*n-1;
    for (int i = 0; i < 2*n+1; i+=2) a[i] = b[j--];
    for (int i = 1; i < 2*n+1; i+=2) a[i] = b[j--];
    a[2*n-1] = val;
    for (ll x : a) cout << x << " ";
    cout << endl;
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