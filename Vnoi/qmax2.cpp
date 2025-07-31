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
int Segtree[4*MAXN], Lazy[4*MAXN];
void Push(int id) {
    Lazy[id*2] += Lazy[id];
    Lazy[id*2+1] += Lazy[id];
    Segtree[id*2] += Lazy[id];
    Segtree[id*2+1] += Lazy[id];
    Lazy[id] = 0;
}
void Update(int id, int l, int r, int u, int v, int k) {
    if (r < u || v < l) return;
    if (u <= l && r <= v) {Lazy[id] += k, Segtree[id] += k; return;}
    int m = (l+r)/2;
    Push(id);
    Update(id*2,l,m,u,v,k);
    Update(id*2+1,m+1,r,u,v,k);
    Segtree[id] = max(Segtree[id*2],Segtree[id*2+1]);
}
int Get(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return INT_MIN;
    if (u <= l && r <= v) return Segtree[id];
    int m = (l+r)/2;
    Push(id);
    int nub1 = Get(id*2,l,m,u,v);
    int nub2 = Get(id*2+1,m+1,r,u,v);
    return max(nub1,nub2);
}
void solve() {
    int n, m; cin >> n >> m;
    fill(Segtree,Segtree+sizeof(Segtree),0);
    fill(Lazy,Lazy+sizeof(Lazy),0);
    while (m--) {
        int t; cin >> t;
        if (t == 0) {
            int x, y; cin >> x >> y;
            int k; cin >> k;
            Update(1,1,n,x,y,k);
        } else {
            int x, y; cin >> x >> y;
            cout << Get(1,1,n,x,y) << endl;
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