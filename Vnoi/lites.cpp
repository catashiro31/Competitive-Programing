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
const int MAXN = 1e5 + 1;
const string NoF = "Name_of_File";
pair<int,int> segtree[MAXN*4];
int lazy[MAXN*4];
void Push(int id) {
    if (lazy[id] == 0) return;
    swap(segtree[id*2].fi,segtree[id*2].se);
    swap(segtree[id*2+1].fi,segtree[id*2+1].se);
    lazy[id*2] = 1 - lazy[id*2];
    lazy[id*2+1] = 1 - lazy[id*2+1];
    lazy[id] = 0;
    return;
}
void Build(int id, int l, int r) {
    if (l == r) {segtree[id] = {1,0}; return;}
    int m = (l+r)/2;
    Build(id*2,l,m);
    Build(id*2+1,m+1,r);
    segtree[id] = {segtree[id*2].fi+segtree[id*2+1].fi,segtree[id*2].se+segtree[id*2+1].se};
    return;
}
void Update(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return;
    if (u <= l && r <= v) {
        lazy[id] = 1 - lazy[id];
        swap(segtree[id].fi,segtree[id].se);
        return;
    }
    int m = (l+r)/2;
    Push(id);
    Update(id*2,l,m,u,v);
    Update(id*2+1,m+1,r,u,v);
    segtree[id] = {segtree[id*2].fi+segtree[id*2+1].fi,segtree[id*2].se+segtree[id*2+1].se};
    return;
}
int Get(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) return segtree[id].se;
    int m = (l+r)/2;
    Push(id);
    return Get(id*2,l,m,u,v) + Get(id*2+1,m+1,r,u,v);
}
void solve() {
    memset(lazy,0,sizeof(lazy));
    int n, m; cin >> n >> m;
    Build(1,1,n);
    while(m--) {
        int t; cin >> t;
        if (!t) {
            int u, v; cin >> u >> v;
            Update(1,1,n,u,v);
        } else {
            int u, v; cin >> u >> v;
            cout << Get(1,1,n,u,v) << endl;
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