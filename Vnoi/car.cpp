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
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;
    ll res = 0, kq = 0;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) ar[i] = i;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if ((res+b[i])*a[i]+(res+b[i]+b[j])*a[j] > (res+b[j])*a[j]+(res+b[i]+b[j])*a[i]) swap(a[i],a[j]), swap(b[i],b[j]), swap(ar[i],ar[j]);
        }
        res += b[i];
        kq += a[i]*res;
    }
    res += b[n-1];
    kq += a[n-1]*res;
    cout << kq << endl;
    for (int x : ar) cout << x+1 << " ";
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