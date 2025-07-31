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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int len = r - l + 1;

    vector<int> left(a.begin(), a.begin() + r);
    vector<int> right(a.begin() + l - 1, a.end());

    sort(all(left));
    sort(all(right));

    ll res = LLONG_MAX;
    ll sum = 0;

    for (int i = 0; i < len; ++i) sum += left[i];
    res = min(res, sum);

    sum = 0;
    for (int i = 0; i < len; ++i) sum += right[i];
    res = min(res, sum);

    sum = 0;
    for (int i = l - 1; i < r; ++i) sum += a[i];
    res = min(res, sum);

    cout << res << '\n';
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