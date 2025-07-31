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
int n, m;
int h[MAXN+1], r[MAXN+1], kq[MAXN+1];
int Segtree[MAXN*4];
void build(int id, int l, int r) {
    if (l == r) {
        Segtree[id] = h[l];
        return;
    }
    int m = (l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    Segtree[id] = max(Segtree[id*2],Segtree[id*2+1]);
}
void Update(int id , int l , int r, int p, int val) {
    if (p < l || p > r) return;
    if (l == r) {
        Segtree[id] = val, h[l] = val;
        return;
    }
    int m = (l+r)/2;
    Update(id*2,l,m,p,val);
    Update(id*2+1,m+1,r,p,val);
    Segtree[id] = max(Segtree[id*2],Segtree[id*2+1]);
}
int Get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return INT_MIN;
    if (u <= l && r <= v) return Segtree[id];
    int m = (l+r)/2;
    int nub1 = Get(id*2,l,m,u,v);
    int nub2 = Get(id*2+1,m+1,r,u,v);
    return max(nub1,nub2);
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= m; i++) cin >> r[i];
    build(1,1,n);
    for (int i = 1; i <= m; i++) {
        int u = 1, v = n; 
        while (u < v) {
            int m = (u+v)/2;
            int left = Get(1,1,n,u,m), right = Get(1,1,n,m+1,v);
            if (left < r[i] && right < r[i]) break;
            else {
                if (left < r[i]) u = m+1;
                else if (right < r[i]) v = m;
                else v = m;
            } 
        }
        if (u != v || h[u] < r[i]) kq[i] = 0;
        else {
            kq[i] = u;
            Update(1,1,n,u,h[u]-r[i]);
        }
    }
    for (int i = 1; i <= m; i++) cout << kq[i] << " ";
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