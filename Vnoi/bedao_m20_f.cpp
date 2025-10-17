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
int A[MAXN], B[MAXN], C[MAXN];
int T[MAXN], X[MAXN], Y[MAXN], K[MAXN];
int segt[4*MAXN];
int kq[MAXN];
void push (int id) {
    if (segt[id] == 0) return;
    segt[id<<1] = segt[id];
    segt[id<<1|1] = segt[id];
    segt[id] = 0;
}
void update(int id, int l, int r, int u, int v, int val) {
    if (r < u || v < l) return;
    if (u <= l && r <= v) {
        segt[id] = val;
        return;
    }
    int m = (l+r)>>1;
    push(id);
    update(id<<1,l,m,u,v,val);
    update(id<<1|1,m+1,r,u,v,val);
}

int get(int id, int l, int r, int p) {
    if (l == r) return segt[id];
    int m = (l+r)>>1;
    push(id);
    if (p <= m) return get(id<<1,l,m,p);
    else return get(id<<1|1,m+1,r,p);
}

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) cin >> B[i];
    for (int i = 1; i <= n; i++) cin >> C[i];
    memset(segt,0,sizeof(segt));
    vector<pair<int,int>> queries[q+2];
    for (int i = 1; i <= q; i++) {
        cin >> T[i];
        if (T[i] == 1 || T[i] == 2) cin >> X[i] >> Y[i] >> K[i];
        else cin >> X[i];
        if (T[i] == 2) update(1,1,n,Y[i],Y[i]+K[i]-1,i);
        else if (T[i] == 3) {
            int v = get(1,1,n,X[i]);
            if (v == 0) kq[i] = C[X[i]];
            else {
                int np = X[v] + (X[i] - Y[v]);
                queries[v].psb({np,i});
            }
        }
    }
    memset(segt,0,sizeof(segt));
    for (int i = 1; i <= q; i++) {
        if (T[i] == 1) update(1,1,n,Y[i],Y[i]+K[i]-1,i);
        for (auto [np,i] : queries[i]) {
            int pos = get(1,1,n,np);
            if (pos == 0) kq[i] = B[np];
            else {
                int npos = X[pos] + np - Y[pos];
                kq[i] = A[npos];
            } 
        }
    }
    for (int i = 1; i <= q; i++) {
        if (T[i] == 3) cout << kq[i] << endl;
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