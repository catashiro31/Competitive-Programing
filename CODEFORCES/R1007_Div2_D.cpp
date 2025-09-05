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
int cal(ll x, int n, const vector<int> &bits, const vector<int> &prefix) {
    if (x <= n) return prefix[x];
    if (x&1) {
        if (n&1) return prefix[n];
        else return prefix[n] ^ prefix[(n+1)/2];
    } else {
        if (n&1) return prefix[n] ^ cal(x/2, n, bits, prefix);
        else return prefix[n] ^ prefix[(n+1)/2] ^ cal(x/2, n, bits, prefix);
    } 
}
void solve() {
    int n; cin >> n;
    ll l, r; cin >> l >> r;
    vector<int> bits(n+1);
    for (int i = 1; i <= n; i++) cin >> bits[i];
    vector<int> prefix(n+1);
    prefix[1] = bits[1];
    for (int i = 2; i <= n; i++) prefix[i] = prefix[i-1] ^ bits[i];
    ll x = r;
    if (x <= n) cout << bits[x] << endl;
    else cout << cal(x/2,n,bits,prefix) << endl;
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