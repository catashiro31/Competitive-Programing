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
int block = 0;
bool Compare (const pair<int,int> &a, const pair<int,int> &b) {
    int pa = a.se / block, pb = b.se/block;
    if (pa != pb) return pa < pb;
    return pa % 2 == 0 ? a.fi < b.fi : a.fi > b.fi;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int q; cin >> q;
    vector<pair<int,int>> query(q);
    for (auto &[u,v] : query) cin >> u >> v;
    vector<pair<int,int>> point(q);
    for (int i = 0; i < q; i++) point[i].fi = query[i].fi, point[i].se = query[i].se;
    while (block * block < n) block++;
    sort(all(point),Compare);
    map<pair<int,int>,int> value;
    vector<int> cnt(n+1,0);
    int val = 0;
    int l = 0, r = 0;
    cnt[a[0]]++;
    for (auto [u,v] : point) {
        --u, --v;
        while (r < v) {
            r++;
            cnt[a[r]]++;
            val += cnt[a[r]] % 2 == 0 ? 1 : 0;
        }        
        while (l > u) {
            l--;
            cnt[a[l]]++;
            val += cnt[a[l]] % 2 == 0 ? 1 : 0;
        }        
        while (l < u) {
            cnt[a[l]]--;
            val -= cnt[a[l]] % 2 == 1 ? 1 : 0;
            l++;
        }        
        while (r > v) {
            cnt[a[r]]--;
            val -= cnt[a[r]] % 2 == 1 ? 1 : 0;
            r--;
        }
        ++u,++v;
        value[{u,v}] = val;
    }
    for (auto [l,r] : query) cout << value[{l,r}] << endl;
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