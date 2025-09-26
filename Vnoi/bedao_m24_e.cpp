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
const int MAXN = 5e5 + 5;
const string NoF = "Name_of_File";
int a[MAXN], prefix[MAXN];
int segmin[4*MAXN], segmax[4*MAXN], lazy[4*MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        segmin[id] = prefix[l];
        segmax[id] = prefix[l];
        return;
    }
    int m = (l+r) >> 1;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
    segmin[id] = min(segmin[id<<1],segmin[id<<1|1]);
    segmax[id] = max(segmax[id<<1],segmax[id<<1|1]);
}

void update(int id, int l, int r, int u, int v, int val) {
    if (r < u || v < l) return;
    if (u <= l && r <= v) {
        lazy[id] += val;
        segmin[id] += val;
        segmax[id] += val;
        return;
    }
    int m = (l+r) >> 1;
    if (lazy[id]) {
        segmin[id<<1] += lazy[id];
        segmin[id<<1|1] += lazy[id];
        lazy[id<<1] += lazy[id];
        lazy[id<<1|1] += lazy[id];
        segmax[id<<1] += lazy[id];
        segmax[id<<1|1] += lazy[id];
        lazy[id] = 0;
    }
    update(id<<1,l,m,u,v,val);
    update(id<<1|1,m+1,r,u,v,val);
    segmin[id] = min(segmin[id<<1],segmin[id<<1|1]);
    segmax[id] = max(segmax[id<<1],segmax[id<<1|1]);
}

int get1(int id, int l, int r, int p) {
    if (l == r) return segmin[id];
    int m = (l+r)>>1;
    if (lazy[id]) {
        segmin[id<<1] += lazy[id];
        segmin[id<<1|1] += lazy[id];
        lazy[id<<1] += lazy[id];
        lazy[id<<1|1] += lazy[id];
        segmax[id<<1] += lazy[id];
        segmax[id<<1|1] += lazy[id];
        lazy[id] = 0;
    }
    if (m < p) return get1(id<<1|1,m+1,r,p);
    return get1(id<<1,l,m,p);
}

int get2(int id, int l, int r, int u, int v, int val) {
    if (r < u || l > v || segmin[id] >= val) return -1;
    if (l == r) return l;
    int m = (l+r)>>1;
    if (lazy[id]) {
        segmin[id<<1] += lazy[id];
        segmin[id<<1|1] += lazy[id];
        lazy[id<<1] += lazy[id];
        lazy[id<<1|1] += lazy[id];
        segmax[id<<1] += lazy[id];
        segmax[id<<1|1] += lazy[id];
        lazy[id] = 0;
    }
    int left = get2(id<<1,l,m,u,v,val);
    if (left != -1) return left;
    return get2(id<<1|1,m+1,r,u,v,val);
}

int get3(int id, int l, int r, int u, int v, int val) {
    if (r < u || l > v || segmax[id] < val || segmin[id] > val) return -1;
    if (l == r) return l;
    int m = (l+r) >> 1;
    if (lazy[id]) {
        segmin[id<<1] += lazy[id];
        segmin[id<<1|1] += lazy[id];
        lazy[id<<1] += lazy[id];
        lazy[id<<1|1] += lazy[id];
        segmax[id<<1] += lazy[id];
        segmax[id<<1|1] += lazy[id];
        lazy[id] = 0;
    }
    int right = get3(id<<1|1,m+1,r,u,v,val);
    if (right != -1) return right;
    return get3(id<<1,l,m,u,v,val);
}

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') a[i+1] = 1;
        else a[i+1] = -1;
    }
    prefix[1] = a[1];
    for (int i = 2; i <= n; i++) prefix[i] = prefix[i-1] + a[i];
    memset(lazy,0,sizeof(lazy));
    build(1,1,n);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            int val = (a[x] == 1 ? -2:2);
            a[x] = -a[x];
            update(1,1,n,x,n,val);
        } else {
            int x; cin >> x;
            if (a[x] < 0) {
                cout << 0 << endl;
                continue;
            }
            int val = (x == 1 ? 0 : get1(1,1,n,x-1));
            int r = get2(1,1,n,x,n,val);
            if (r == -1) r = n+1;
            int p = get3(1,1,n,x,r-1,val);
            if (p == -1) cout << 0 << endl;
            else cout << p-x+1 << endl;
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