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
ll a[MAXN], segtree[MAXN*4];
void Build(int id, int l, int r) {
    if (l == r) {
        segtree[id] = a[l];
        return;
    }
    int m = (l+r)/2;
    Build(id*2,l,m);
    Build(id*2+1,m+1,r);
    segtree[id] = segtree[id*2]+segtree[id*2+1];
}
void Update(int id, int l, int r, int k, ll u) {
    if (k < l || r < k) return;
    if (l == r) {
        segtree[id] = u;
        return;
    }
    int m = (l+r)/2;
    Update(id*2,l,m,k,u);
    Update(id*2+1,m+1,r,k,u);
    segtree[id] = segtree[id*2]+segtree[id*2+1];
}
ll Get(int id, int l, int r, int u, int v) {
    if ( r < u || v < l) return 0;
    if (u <= l && r <= v) return segtree[id];
    int m = (l+r)/2;
    ll nub1 = Get(id*2,l,m,u,v), nub2 = Get(id*2+1,m+1,r,u,v);
    return nub1 + nub2;
}
void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n;i++) cin >> a[i];
    Build(1,1,n);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int k; cin >> k;
            ll u; cin >> u;
            Update(1,1,n,k,u);
        } else {
            int a, b; cin >> a >> b;
            cout << Get(1,1,n,a,b) << endl;
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
    int t = 1;
    while(t--) {
        solve();
    }
}