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
vector<ll> prime;
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    sort(all(a),greater<>());
    vector<ll> prefix1(n), prefix2(n);
    prefix1[0] = prime[0], prefix2[0] = a[0];
    for (int i = 1; i < n; i++) prefix1[i] = prefix1[i-1]+prime[i], prefix2[i] = prefix2[i-1]+a[i];
    for (int i = n-1; i >= 0; i--) {
        if (prefix1[i] <= prefix2[i]) {
            cout << n-1-i << endl;
            return;
        }
    }
    cout << n << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<bool> c(1e7+1,false);
    for (ll i = 2; i <= 1e7; i++) {
        if (c[i]) continue;
        prime.psb(i);
        if (sz(prime) >= 4e5+2) break;
        for (ll j = i*i; j <= 1e7; j+=i) c[j] = true;
    }
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
}