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
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int q; cin >> q;
    vector<pair<pair<int,int>,int>> query(q);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        --l, --r;
        query[i] = {{l,r},i};
    }
    int s = (int)sqrt(n);
    sort(all(query),[&](auto &a, auto &b){
        if (a.fi.fi / s != b.fi.fi / s) return a.fi.fi / s < b.fi.fi / s;
        return a.fi.se < b.fi.se;
    });
    int cl = 0, cr= -1, val = 0;
    vector<int> kq(q), sl(1e6+5,0);
    auto ad = [&](int i) {
        sl[a[i]]++;
        if (sl[a[i]] == 1) val++; 
    };
    auto rm = [&](int i) {
        sl[a[i]]--;
        if (sl[a[i]] == 0) val--;
    };
    for (auto [lr,id] : query) {
        auto [l,r] = lr;
        while(cr < r) ad(++cr);
        while(cl < l) rm(cl++);
        while(cr > r) rm(cr--);
        while(cl > l) ad(--cl);
        kq[id] = val;
    }
    for (int x : kq) cout << x << endl;
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