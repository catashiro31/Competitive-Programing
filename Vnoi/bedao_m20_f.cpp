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
const int MAXN = 5e5 + 1;
const string NoF = "Name_of_File";
vector<int> segB(4*MAXN,INT_MAX), segC(4*MAXN,INT_MAX);
vector<int> lazyB(4*MAXN,INT_MAX), lazyC(4*MAXN,INT_MAX);
vector<int> A(MAXN), B(MAXN), C(MAXN);

void update(int id, vector<int> &segtree, vector<int> &lazy, int l, int r, int u, int v, int val) {
    if (r < u || v < l) return;
    if (u <= l && r <= v) {
        segtree[id] = val;
        lazy[id] = val;
        return;
    }
    int m = (l+r)>>1;
    if (lazy[id] != INT_MAX) {
        segtree[id<<1] = segtree[id<<1|1] = lazy[id];
        lazy[id<<1] = lazy[id<<1|1] = lazy[id];
        lazy[id] = INT_MAX;
    }
    update(id<<1,segtree,lazy,l,m,u,v,val);
    update(id<<1|1,segtree,lazy,m+1,r,u,v,val);
}

int get(int id, vector<int> &segtree, vector<int> &lazy, int l, int r, int p) {
    if (l == r) return segtree[id];
    int m = (l+r)>>1;
    if (lazy[id] != INT_MAX) {
        segtree[id<<1] = segtree[id<<1|1] = lazy[id];
        lazy[id<<1] = lazy[id<<1|1] = lazy[id];
        lazy[id] = INT_MAX;
    }
    if (p <= m) return get(id<<1,segtree,lazy,l,m,p);
    else return get(id<<1|1,segtree,lazy,m+1,r,p);
}


void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) cin >> B[i];
    for (int i = 1; i <= n; i++) cin >> C[i]; 
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y, k; cin >> x >> y >> k;
            update(1,segB,lazyB,1,n,y,y+k-1,x-y);
        } else if (t== 2) {
            int x, y, k; cin >> x >> y >> k;
            update(1,segC,lazyC,1,n,y,y+k-1,x-y);
        } else {
            int x; cin >> x;
            int getc = get(1,segC,lazyC,1,n,x);
            if (getc == INT_MAX) cout << C[x] << endl;
            else {
                x = x + getc;
                int getb = get(1,segB,lazyB,1,n,x);
                if (getb == INT_MAX) cout << B[x] << endl;
                else {
                    x = x + getb;
                    cout << A[x] << endl;
                }
            }
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