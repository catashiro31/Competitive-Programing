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
const int MAXN = 3e5 + 1;
const string NoF = "Name_of_File";
int n;
vector<ll> BIT(MAXN,0);
void Update(int id, int x) {
    while (id <= n) {
        BIT[id] ^= x;
        id += (id & (-id));
    }
}
int Get(int id) {
    int ans = 0;
    while (id) {
       ans ^= BIT[id];
       id -= (id & (-id)); 
    }
    return ans;
}
void solve() {
    int q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> kq(q);
    vector<pair<pair<int,int>,int>> query(q);
    for (int i = 0; i < q; i++) {
        cin >> query[i].fi.fi >> query[i].fi.se;
        query[i].se = i;
    } 
    sort(all(query),[](auto a, auto b) {
        return a.fi.se < b.fi.se;
    });
    int i = 0;
    map<int,int> p;
    for (int j = 0; j < n; j++) {
        if (p[a[j]] != 0) Update(p[a[j]],a[j]);
        p[a[j]] = j+1;
        Update(p[a[j]],a[j]);
        while (i < q && query[i].fi.se <= j+1) {
            kq[query[i].se] = Get(query[i].fi.se) ^ Get(query[i].fi.fi-1);
            i++;
        }
    }
    for (int x : kq) cout << x << " ";
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