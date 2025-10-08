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
const int MAXN = 1e5 + 1;
const string NoF = "Name_of_File";
int a[MAXN], b[MAXN];
pair<int,int> segtree[MAXN*4];
bool lazy[MAXN*4];

void build(int id, int l, int r) {
    if (l == r) {
        segtree[id] = {b[l]&1,!(b[l]&1)};
        return;
    }
    int m = (l+r)>>1;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
    segtree[id] = {segtree[id<<1].fi+segtree[id<<1|1].fi, segtree[id<<1].se+segtree[id<<1|1].se};
}

void push(int id) {
    if (!lazy[id]) return;
    lazy[id<<1] = 1 - lazy[id<<1];
    lazy[id<<1|1] = 1 - lazy[id<<1|1];
    segtree[id<<1] = {segtree[id<<1].se,segtree[id<<1].fi};
    segtree[id<<1|1] = {segtree[id<<1|1].se,segtree[id<<1|1].fi};
    lazy[id] = 0; 
}

void update(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return;
    if (u <= l && r <= v) {
        lazy[id] = 1-lazy[id];
        segtree[id] = {segtree[id].se,segtree[id].fi};
        return;
    }
    int m = (l+r)>>1;
    push(id);
    update(id<<1,l,m,u,v);
    update(id<<1|1,m+1,r,u,v);
    segtree[id] = {segtree[id<<1].fi+segtree[id<<1|1].fi, segtree[id<<1].se+segtree[id<<1|1].se};
}

pair<int,int> get(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return {0,0};
    if (u <= l && r <= v) return segtree[id];
    int m = (l+r)>>1;
    push(id);
    pair<int,int> g1 = get(id<<1,l,m,u,v), g2 = get(id<<1|1,m+1,r,u,v);
    return {g1.fi+g2.fi,g1.se+g2.se};
}


void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    b[0] = 0;
    for (int i = 1; i <= n; i++) b[i] = b[i-1] + a[i];
    build(1,0,n);
    while(q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, v; cin >> i >> v;
            if ((a[i]&1) != (v&1)) update(1,0,n,i,n);
            a[i] = v;
        } else {
            int u, v; cin >> u >> v;
            pair<int,int> sl = get(1,0,n,u-1,v);
            cout << 1LL*sl.fi*(sl.fi-1)/2 + 1LL*sl.se*(sl.se-1)/2 << endl;
        }
    }
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